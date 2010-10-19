#include <iostream>
#include <string>
#include <set>
#include <boost/foreach.hpp>

using namespace std;

int main() {
    set<string> things_to_buy;

    things_to_buy.insert("peanut butter");
    things_to_buy.insert("jelly");
    things_to_buy.insert("bread");

    cout << "Contents of initial set:" << endl;
    BOOST_FOREACH(const string &item, things_to_buy) {
        cout << "  " << item << endl;
    }

    set<string*> things_to_buy_ptr;

    BOOST_FOREACH(const string &item, things_to_buy) {
        things_to_buy_ptr.insert((string *)&item);
    }

    // Print contents
    cout << "Contents of referenced set:" << endl;
    BOOST_FOREACH(string* const &item, things_to_buy_ptr) {
        cout << "  " << *item << endl;
    }

    // Try adding same pointers again.
    BOOST_FOREACH(const string &item, things_to_buy) {
        things_to_buy_ptr.insert((string *)&item);
    }

    // Print contents again - should be the same
    cout << "Contents of referenced set after trying to add items again:" << endl;
    BOOST_FOREACH(string* const &item, things_to_buy_ptr) {
        cout << "  " << *item << endl;
    }
    cout << "NOTE: since we're using std::set, the items are only added once." << endl;

    return 0;
}
