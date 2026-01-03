package main

import "time"

// order struct to hold order information
type order struct {
	id       int
	quantity int
	price    float64
	createdAt time.Time
}

// newOrder is a constructor function for creating a new order
func newOrder(id int, quantity int, price float64) *order {
	return &order{
		id:       id,
		quantity: quantity,
		price:    price,
		createdAt: time.Now(),
	}
}

// setter  and getter methods for order struct

// using pointer receiver to modify the original struct
func (o *order) setQuantity(qty int) {
	o.quantity = qty
}

// using value receiver to get the quantity
func (o *order) getQuantity() int {
	return o.quantity	
}


func main() {
	// Create a new order using the constructor function
	myOrder := newOrder(1, 5, 99.99)

	// Print order details
	println("Order ID:", myOrder.id)
	println("Quantity:", myOrder.quantity)
	println("Price:", myOrder.price)

	language := struct {
		name    string
		version string
	}{
		name:    "Go",
		version: "1.20",
	}
	
	println("Language:", language)
}

