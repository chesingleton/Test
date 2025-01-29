#include "LibInterface.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
Library ECU;

int main(){
    Book book1("to kill a mockingbird", "harper lee", 89021783897123);
    ECU.addBook(book1);
    ECU.displayBooks();
    Member m1("che singleton",123091230);
    Member m2("bob singleton",123091231);
    m1.checkOutBook(book1);
    m2.checkOutBook(book1);
    m1.displayBooks(m1);
}
