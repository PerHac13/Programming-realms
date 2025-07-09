interface Printer {
  void print();
}

interface Scanner {
  void scan();
}

interface FaxMachine {
  void fax();
}

class BasicPrinter implements Printer {
  @Override
  public void print() {
    // Printing functionality
  }
}

class AllInOnePrinter implements Printer, Scanner, FaxMachine {
  @Override
  public void print() {
    // Printing functionality
  }
  @Override
  public void scan() {
    // Scanning functionality
  }
  @Override
  public void fax() {
    // Fax functionality
  }
}


// interface Machine {
//   void print();
//   void scan();
//   void fax();
// }

// class AllInOnePrinter implements Machine {
//   @Override public void print() {
//     // Printing functionality
//   }
//   @Override public void scan() {
//     // Scanning functionality
//   }
//   @Override public void fax() {
//     // Fax functionality
//   }
// }

// class BasicPrinter implements Machine {
//   @Override public void print() {
//     // Printing functionality
//   }
//   @Override public void scan() {
//     // Problem: Basic printer can't scan!
//     throw new UnsupportedOperationException("Cannot scan");
//   }
//   @Override public void fax() {
//     // Problem: Basic printer can't fax!
//     throw new UnsupportedOperationException("Cannot fax");
//   }
// }