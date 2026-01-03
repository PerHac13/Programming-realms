package responses

import (
	"encoding/json"
	"fmt"
	"net/http"
	"strings"

	"github.com/go-playground/validator/v10"
)

type ErrorResponse struct {
	Status string `json:"status"`
	Error string `json:"error"`
}

const (
	StatusSuccess = "success"
	StatusError   = "error"
)

func WriteJSONResponse(w http.ResponseWriter, statusCode int, data interface{}) error {
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(statusCode)
	return json.NewEncoder(w).Encode(data)
}

func GeneralError(err error) ErrorResponse {
	return ErrorResponse{
		Status: StatusError,
		Error: err.Error(),
	}
}

func ValidationError(errs validator.ValidationErrors) ErrorResponse {
	var errMsgs []string

	for _, err := range errs {
		switch err.ActualTag() {
			case "required":
				errMsgs = append(errMsgs, fmt.Sprintf("field %s is required field",  err.Field()))
			case "gt":
				errMsgs = append(errMsgs, fmt.Sprintf("field %s must be greater than %s", err.Field(), err.Param()))
			case "gte":
				errMsgs = append(errMsgs, fmt.Sprintf("field %s must be greater than or equal to %s", err.Field(), err.Param()))
			default:
				errMsgs = append(errMsgs, fmt.Sprintf("field %s is not valid", err.Field()))
		}
	}

	return ErrorResponse{
		Status: StatusError,
		Error:  strings.Join(errMsgs, ", "),
	}
}