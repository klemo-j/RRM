#include "Teleop.hpp"
#include <iostream>
#include <vector>

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Teleop>();

    std::cout << "--- RRM Service Teleop (Zadanie 1.3) ---" << std::endl;

    while (rclcpp::ok()) {
        std::vector<double> cielove_polohy(3);
        double max_v;

        std::cout << "\nZadajte polohy pre 3 klby:" << std::endl;
        std::cout << "Klb 1: "; if (!(std::cin >> cielove_polohy[0])) break;
        std::cout << "Klb 2: "; if (!(std::cin >> cielove_polohy[1])) break;
        std::cout << "Klb 3: "; if (!(std::cin >> cielove_polohy[2])) break;
        std::cout << "Maximalna rychlost od 0 po 100: "; if (!(std::cin >> max_v)) break;


        if (!(std::cin >> max_v)) {
            rclcpp::shutdown();
            return 0;
        }


        while (max_v <= 0.0 || max_v > 100.0) {
            std::cout << ">>> Neplatna rychlost! Hodnota musi byt vacsia ako 0 a maximalne 100.\n";
            std::cout << "Zadajte rychlost znova: ";


            if (!(std::cin >> max_v)) {
                rclcpp::shutdown();
                return 0;
            }
        }



        max_v = max_v / 100.0;

        rclcpp::spin_some(node);

        if (node->move(cielove_polohy, max_v)) {
            std::cout << ">>> Prikaz odoslany a vykonany." << std::endl;
        }gitgitgitdsaasggggggdasdasdasdasd
			else{
            std::cout << ">>> Chyba pri vykonavani prikazu." << std::endl;
        }
    }

    rclcpp::shutdown();
    return 0;
}