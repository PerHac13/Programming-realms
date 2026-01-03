package main

// enumerated type for order status
type OrderStatus int

const (
	Pending OrderStatus = iota
	Shipped
	Delivered
	Canceled
)

type GameStatus string

const (
	Active   GameStatus = "active"
	Paused   GameStatus = "paused"
	Finished GameStatus = "finished"
)

func changeOrderStatus(status OrderStatus) string {
	println("status", status)
	switch status {
	case Pending:
		return "Order is pending."
	case Shipped:
		return "Order has been shipped."
	case Delivered:
		return "Order has been delivered."
	case Canceled:
		return "Order has been canceled."
	default:
		return "Unknown order status."
	}
}

func main() {
	statusMessage := changeOrderStatus(Shipped)
	println(statusMessage)
}