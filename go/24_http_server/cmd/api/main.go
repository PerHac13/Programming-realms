package main

import (
	"context"
	"fmt"
	"log"
	"log/slog"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/pH/go/http-server/internal/config"
	"github.com/pH/go/http-server/internal/http/handlers/crud"
	"github.com/pH/go/http-server/internal/storage/sqlite"
)

func main() {
	fmt.Println("Hello, HTTP Server!")

	// load config
	cfg := config.MustLoad()

	// db connection would be here
	storage, err :=sqlite.NewSqliteStorage(cfg)

	if err != nil {
		log.Fatalf("Failed to connect to storage: %v\n", err)
	}

	slog.Info("storage initialized", slog.String("env", fmt.Sprintf("%T", cfg.Env)))
	// setup router
	router := http.NewServeMux()
	
	// setup routes
	router.HandleFunc("GET /health", func(w http.ResponseWriter, r *http.Request) {
		w.WriteHeader(http.StatusOK)
		w.Write([]byte("OK"))
		
	})

	router.HandleFunc("POST /api/crud", crud.New(storage))
	router.HandleFunc("GET /api/crud/{id}", crud.GetById(storage))
	router.HandleFunc("PUT /api/crud/{id}", crud.UpdateById(storage))
	router.HandleFunc("DELETE /api/crud/{id}", crud.DeleteById(storage))
	router.HandleFunc("GET /api/crud", crud.GetList(storage))

	// setup server

	server := http.Server{
		Handler: router,
		Addr: cfg.HTTPServer.Address,
		// ReadTimeout: cfg.HTTPServer.ReadTimeout,
		// WriteTimeout: cfg.HTTPServer.WriteTimeout,
		// IdleTimeout: cfg.HTTPServer.IdleTimeout,
	}
	// start server
	fmt.Printf("Server Started %s", cfg.HTTPServer.Address)

	stop := make(chan os.Signal,1)

	signal.Notify(stop, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)

	go func() {

		err := server.ListenAndServe()
		if err != nil {
			log.Fatalf("Failed to start server: %v\n", err)
		}
	}()

	<- stop

	slog.Info("Shutting down server...")

	ctx, cancel := context.WithTimeout(context.Background(), 5* time.Second)
	defer cancel()

	if err := server.Shutdown(ctx); err != nil {
		slog.Error("Server forced to shutdown:", slog.String("error", err.Error()))
	}

	slog.Info("Server exiting")

}
