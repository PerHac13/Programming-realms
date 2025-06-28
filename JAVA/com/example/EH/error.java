class Error {
    public static void main(String[] args) {
        try {
            int result = 10 / 0; // This will cause an ArithmeticException
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } finally {
            System.out.println("This block always executes.");
        }
        
        // Example of a custom exception
        try {
            throw new CustomException("This is a custom exception message.");
        } catch (CustomException e) {
            System.out.println("Caught custom exception: " + e.getMessage());
        }

        System.out.println("Program continues after handling exceptions.");
    }
}