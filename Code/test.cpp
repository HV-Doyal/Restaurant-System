
#include "catch_amalgamated.hpp"
#include "menu.h"



// TEST_CASE( "Testing the Display Menu function", "[Display-function]" ) {
//     Menu menu;
//     menu.displayMenuItems();
// }

TEST_CASE( "Testing the to lowercase function", "[Lowercase-function]" ) {
    Menu menu;
    menu.getloadMenuFromCSV("maincourse.csv");
    REQUIRE(menu.toLowercase("UpPer1123") == "upper1123");
    REQUIRE(menu.toLowercase("UpP e r  ") == "upp e r  ");
    REQUIRE(menu.toLowercase("UpPer1123") == "upper1123");
    REQUIRE(menu.toLowercase("+U-pP?e/r.") == "+u-pp?e/r.");

}

TEST_CASE( "Testing the get price function", "[GetPrice-function]" ) {
    Menu menu;
    menu.getloadMenuFromCSV("maincourse.csv");
    REQUIRE(menu.getPrice("Dhal Pu") == "");
    REQUIRE(menu.getPrice("") == "0.00");
    REQUIRE(menu.getPrice("Dhal Puri") == "7.50");
}

// TEST_CASE( "Testing the search menu function", "[Search-function]" ) {
//     Menu menu;
//     menu.getloadMenuFromCSV("maincourse.csv");
//     menu.searchMenuItem();
//     menu.searchMenuItem();
//     menu.searchMenuItem();
//     menu.searchMenuItem();
// }

// TEST_CASE( "Testing the add menu item function", "[add-function]" ) {
//     Menu menu;
//     menu.addMenuItems();
//     menu.addMenuItems();
//     menu.addMenuItems();
//     menu.displayMenuItems();
// }

// TEST_CASE( "Testing the remove menu item function", "[remove-function]" ) {
//     Menu menu;
//     menu.removeMenuItems();
//     menu.removeMenuItems();
//     menu.removeMenuItems();
// }

