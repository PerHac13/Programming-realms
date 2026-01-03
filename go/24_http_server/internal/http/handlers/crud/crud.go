package crud

import (
	"encoding/json"
	"errors"
	"io"
	"log/slog"
	"net/http"
	"strconv"

	"github.com/go-playground/validator/v10"
	"github.com/pH/go/http-server/internal/storage"
	"github.com/pH/go/http-server/internal/types"
	"github.com/pH/go/http-server/internal/utils/responses"
)

func New(storage storage.Storage) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {

		slog.Info("Create csalled")
		var item types.Item

		err := json.NewDecoder(r.Body).Decode(&item)

		if errors.Is(err, io.EOF) {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}

		if err != nil {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}

		// request validation
		if err := validator.New().Struct(item); err != nil {
			validateErrs, ok := err.(validator.ValidationErrors)
			if !ok {
				responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
				return
			}
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.ValidationError(validateErrs))
			return
		}


		lastId, err := storage.CreateItem(item.Name, item.Price, item.Quantity)

		if err != nil {
			responses.WriteJSONResponse(w, http.StatusInternalServerError, responses.GeneralError(err))
			return
		}
		slog.Info("Item created", slog.Int64("id", lastId))
		responses.WriteJSONResponse(w, http.StatusCreated, map[string]interface{}{
			"success": "true",
			"msg":	 "Item created successfully",
			"id":	 string(lastId),
		})

		


		
		
	}
}

func GetById(storage storage.Storage) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		slog.Info("GetById called")
		id := r.PathValue("id")
		slog.Info("Fetching item", slog.String("id", id))

		intId, err := strconv.ParseInt(id, 10, 64)
		if err != nil {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}
		item, err := storage.GetItemById(intId)

		if err != nil {
			slog.Error("Error fetching item", slog.String("id", id))
			responses.WriteJSONResponse(w, http.StatusInternalServerError, responses.GeneralError(err))
			return
		}

		responses.WriteJSONResponse(w, http.StatusOK, item)
	}
}

func GetList(storage storage.Storage) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		slog.Info("GetList called")
		items, err := storage.GetItems()

		if err != nil {
			slog.Error("Error fetching items")
			responses.WriteJSONResponse(w, http.StatusInternalServerError, responses.GeneralError(err))
			return
		}

		responses.WriteJSONResponse(w, http.StatusOK, items)
	}
}

func UpdateById(storage storage.Storage) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		slog.Info("UpdateById called")
		id := r.PathValue("id")
		slog.Info("Updating item", slog.String("id", id))

		intId, err := strconv.ParseInt(id, 10, 64)
		if err != nil {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}

		var item types.Item

		err = json.NewDecoder(r.Body).Decode(&item)

		if errors.Is(err, io.EOF) {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}

		if err != nil {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}

		// request validation
		if err := validator.New().Struct(item); err != nil {
			validateErrs, ok := err.(validator.ValidationErrors)
			if !ok {
				responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
				return
			}
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.ValidationError(validateErrs))
		}

		err = storage.UpdateItem(intId, item.Name, item.Price, item.Quantity)

		if err != nil {
			slog.Error("Error updating item", slog.String("id", id))
			responses.WriteJSONResponse(w, http.StatusInternalServerError, responses.GeneralError(err))
			return
		}

		slog.Info("Item updated", slog.String("id", id))
		responses.WriteJSONResponse(w, http.StatusOK, map[string]interface{}{
			"success": "true",
			"msg":	 "Item updated successfully",
			"id":	 id,
		})
	}
}

func DeleteById(storage storage.Storage) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		slog.Info("DeleteById called")
		id := r.PathValue("id")
		slog.Info("Deleting item", slog.String("id", id))

		intId, err := strconv.ParseInt(id, 10, 64)
		if err != nil {
			responses.WriteJSONResponse(w, http.StatusBadRequest, responses.GeneralError(err))
			return
		}

		err = storage.DeleteItem(intId)

		if err != nil {
			slog.Error("Error deleting item", slog.String("id", id))
			responses.WriteJSONResponse(w, http.StatusInternalServerError, responses.GeneralError(err))
			return
		}

		slog.Info("Item deleted", slog.String("id", id))
		responses.WriteJSONResponse(w, http.StatusOK, map[string]interface{}{
			"success": "true",
			"msg":	 "Item deleted successfully",
			"id":	 id,
		})
	}
}