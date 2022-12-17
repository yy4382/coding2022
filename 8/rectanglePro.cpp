#include <iostream>

class rectangle {
   private:
    double len_;
    double wid_;

   public:
    rectangle(double len, double wid) : len_(len), wid_(wid) {}
    rectangle() {}
    double area() { return len_ * wid_; }
};

class cuboid : public rectangle {
   private:
    double height_;

   public:
    cuboid(double len, double wid, double height)
        : rectangle(len, wid), height_(height) {}
    double vol() { return area() * height_; }
};

int main() {
    double len, wid, hei;
    std::cin >> len >> wid;
    rectangle rec(len, wid);
    double area = rec.area();
    std::cin >> len >> wid >> hei;
    cuboid cu(len, wid, hei);
    double vol = cu.vol();
    std::cout << area << " " << vol << std::endl;
    return 0;
}