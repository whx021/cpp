#include "Gun.h"
#include "Soldier.h"

void test() {
    Soldier san_duo("xun_san_duo");
    san_duo.addGun(new Gun("AK47"));
    san_duo.addBulletToGun(20);
    san_duo.fire();
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}