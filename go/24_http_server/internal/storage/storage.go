package storage

import "github.com/pH/go/http-server/internal/types"


type Storage interface {
	CreateItem(name string, price float64, quantity int) (int64, error)
	GetItemById(id int64) (types.Item, error)
	GetItems() ([]types.Item, error)
	UpdateItem(id int64, name string, price float64, quantity int) error
	DeleteItem(id int64) error

}