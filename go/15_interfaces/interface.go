package main

// these are concrete implementations without interface abstraction
// type payment struct {}

// type razorpay struct {}

// func (r razorpay) processPayment(amount int) {
// 	// Logic to process payment via Razorpay
// 	println("Processing payment of", amount, "via Razorpay")
// }
// type stripe struct {}

// func (s stripe) processPayment(amount int) {
// 	// Logic to process payment via Stripe
// 	println("Processing payment of", amount, "via Stripe")
// }

// func (p payment) makePayment(amount int) {
// 	razorpayPaymentGW := razorpay{}
// 	razorpayPaymentGW.processPayment(amount)
// }

// with interface abstraction

type PaymentGateway interface {
	processPayment(amount int)
}

type payment struct {
	gateway PaymentGateway
}

// method to make payment using the specified payment gateway
// razorpay and stripe both implement the PaymentGateway interface
func (p payment) makePayment(amount int) {
	p.gateway.processPayment(amount)
}

type razorpay struct{}

func (r razorpay) processPayment(amount int) {
	// Logic to process payment via Razorpay
	println("Processing payment of", amount, "via Razorpay")
}

type stripe struct{}

func (s stripe) processPayment(amount int) {
	// Logic to process payment via Stripe
	println("Processing payment of", amount, "via Stripe")
}

func main() {

	// Using Razorpay as the payment gateway
	razorpayGateway := razorpay{}
	payment1 := payment{gateway: razorpayGateway}
	payment1.makePayment(100)

	// Using Stripe as the payment gateway
	stripeGateway := stripe{}
	payment2 := payment{gateway: stripeGateway}
	payment2.makePayment(200)

}