package types

type Item struct {
	ID   int64 `json:"id"`
	Name string `json:"name" validate:"required"`
	Price float64 `json:"price" validate:"required,gt=0"`
	Quantity int    `json:"quantity" validate:"required,gte=0"`
}