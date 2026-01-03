package sqlite

import (
	"database/sql"
	"fmt"

	_ "github.com/mattn/go-sqlite3"
	"github.com/pH/go/http-server/internal/config"
	"github.com/pH/go/http-server/internal/types"
)


type SqliteStorage struct {
	// db connection and other fields
	DB *sql.DB
}

func NewSqliteStorage(cfg *config.Config) (*SqliteStorage, error) {
	// initialize and return SqliteStorage
	db, err := sql.Open("sqlite3", cfg.StoragePath)
	if err != nil {
		return nil, err
	}

	_ , err = db.Exec(`CREATE TABLE IF NOT EXISTS items (
		id INTEGER PRIMARY KEY AUTOINCREMENT,
		name TEXT NOT NULL,
		price REAL NOT NULL,
		quantity INTEGER NOT NULL DEFAULT 0
	);`)

	if err != nil {
		return nil, err
	}

	return &SqliteStorage{
		DB: db,
	}, nil
}

func (s *SqliteStorage) CreateItem( name string, price float64, quantity int) (int64, error) {

	stmt, err := s.DB.Prepare("INSERT INTO students (name, price, quantity) VALUE (?, ?, ?)")

	if err != nil {
		return 0, err
	}
	defer stmt.Close()

	result, err := stmt.Exec(name, price, quantity)

	if err != nil {
		return 0, err
	}

	lastId, err := result.LastInsertId()

	if err != nil {
		return 0, err
	}

	return lastId, nil
}

func (s *SqliteStorage) GetItemById(id int64) (types.Item, error) {
	var item types.Item
	
	// row := s.DB.QueryRow("SELECT id, name, price, quantity FROM items WHERE id = ?", id)
	
	stmt, err := s.DB.Prepare("SELECT id, name, price, quantity FROM items WHERE id = ? LIMIT 1")

	if err != nil {
		return item, err
	}
	defer stmt.Close()
	

	err = stmt.QueryRow(id).Scan(&item.ID, &item.Name, &item.Price, &item.Quantity)

	if err != nil {
		if err == sql.ErrNoRows {
			return item, fmt.Errorf("no item found with id %s", id)
		}
		return item, fmt.Errorf("query error: %w", err)
	}

	return item, nil
}

func (s *SqliteStorage) GetItems() ([]types.Item, error) {
	var items []types.Item

	rows, err := s.DB.Query("SELECT id, name, price, quantity FROM items")

	if err != nil {
		return items, err
	}
	defer rows.Close()

	for rows.Next() {
		var item types.Item
		err := rows.Scan(&item.ID, &item.Name, &item.Price, &item.Quantity)
		if err != nil {
			return items, err
		}
		items = append(items, item)
	}

	if err = rows.Err(); err != nil {
		return items, err
	}

	return items, nil
}

func (s *SqliteStorage) UpdateItem(id int64, name string, price float64, quantity int) error {

	// might not need to change every field

	stmt, err := s.DB.Prepare("UPDATE items SET name = ?, price = ?, quantity = ? WHERE id = ?")

	if err != nil {
		return err
	}
	defer stmt.Close()

	_, err = stmt.Exec(name, price, quantity, id)

	if err != nil {
		return err
	}

	return nil
}

func (s *SqliteStorage) DeleteItem(id int64) error {
	stmt, err := s.DB.Prepare("DELETE FROM items WHERE id = ?")

	if err != nil {
		return err
	}
	defer stmt.Close()

	_, err = stmt.Exec(id)

	if err != nil {
		return err
	}

	return nil
}