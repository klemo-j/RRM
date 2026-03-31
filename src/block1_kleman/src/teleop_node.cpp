#include "Teleop.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Teleop>();

    while (rclcpp::ok()) {
        char volba;
        std::cout << "\n----------------------------------------" << std::endl;
        // PRIDANA VOLBA (i) DO MENU
        std::cout << "MENU: (m) - Pohyb po klboch, (i) - Pohyb XYZ (IK), (s) - Ulozit bod, (l) - Nacitat, (q) - Koniec" << std::endl;
        std::cout << "Vasa volba: ";
        std::cin >> volba;

        if (volba == 'q') break;

        if (volba == 'm') {
            std::vector<double> ciel(3);
            double v;
            std::cout << "Zadajte polohu klbu 1: "; if (!(std::cin >> ciel[0])) break;
            std::cout << "Zadajte polohu klbu 2: "; if (!(std::cin >> ciel[1])) break;
            std::cout << "Zadajte polohu klbu 3: "; if (!(std::cin >> ciel[2])) break;
            std::cout << "Zadajte rychlost (0-100): "; if (!(std::cin >> v)) break;

            node->move(ciel, v / 100.0);
            std::cout << ">>> Prikaz na pohyb odoslany." << std::endl;
        }
        else if (volba == 'i' || volba == 'I') {
            // NOVA LOGIKA PRE KARTESZKY POHYB
            double x, y, z, v;
            std::cout << "Zadajte cielove X: "; if (!(std::cin >> x)) break;
            std::cout << "Zadajte cielove Y: "; if (!(std::cin >> y)) break;
            std::cout << "Zadajte cielove Z: "; if (!(std::cin >> z)) break;
            std::cout << "Zadajte rychlost (0-100): "; if (!(std::cin >> v)) break;

            node->move_ik(x, y, z, v / 100.0);
            std::cout << ">>> Prikaz spracovany manazerom pohybu." << std::endl;
        }
        else if (volba == 's') {
            auto request = std::make_shared<kleman_interface::srv::SavePoint::Request>();
            request->velocity = node->get_last_velocity();
            auto result = node->get_save_client()->async_send_request(request);
            std::cout << ">>> Poziadavka na ulozenie odoslana do Loggera." << std::endl;
        }
        else if (volba == 'l' || volba == 'L') {
            std::ifstream infile("trajektoria.txt");
            if (!infile.is_open()) {
                std::cout << ">>> Chyba: Subor trajektoria.txt neexistuje!" << std::endl;
            } else {
                std::string line;
                while (std::getline(infile, line)) {
                    std::stringstream ss(line);
                    int id; double p1, p2, p3, vel;
                    if (ss >> id >> p1 >> p2 >> p3 >> vel) {
                        std::cout << ">>> Vykonavam bod ID: " << id << std::endl;
                        node->move({p1, p2, p3}, vel);
                        rclcpp::sleep_for(std::chrono::milliseconds(500));
                        rclcpp::spin_some(node);
                    }
                }
                infile.close();
                std::cout << ">>> Trajektoria dokoncena." << std::endl;
            }
        }

        rclcpp::spin_some(node);
    }

    rclcpp::shutdown();
    return 0;
}