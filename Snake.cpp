#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>

int rows = 5;
int columns = 7;
std::vector<char> tab(rows * columns, '.');
std::vector<std::pair<int, int>> snake;
std::pair<int, int> apple;

void init_snake() {
    snake.push_back({2, 3});
    snake.push_back({2, 4});
    snake.push_back({2, 5});
}

void reset_board() {
    std::fill(tab.begin(), tab.end(), '.');
}

void add_snake_to_board() {
    tab[snake[0].first * columns + snake[0].second] = 'O';
    for (size_t i = 1; i < snake.size(); i++) {
        tab[snake[i].first * columns + snake[i].second] = 'o';
    }
}

void generate_apple() {
    apple = {3, 4};
}

void add_apple_to_board() {
    tab[apple.first * columns + apple.second] = '@';
}

void draw_board() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            std::cout << tab[r * columns + c];
        }
        std::cout << std::endl;
    }
}

void print_message(const std::string &msg) {
    std::cout << msg;
}

void move_snake(int dr, int dc) {
    int new_r = snake[0].first + dr;
    int new_c = snake[0].second + dc;
    
    if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= columns) {
        print_message("Game Over!\n");
        exit(2);
    }
    
    for (const auto &segment : snake) {
        if (segment.first == new_r && segment.second == new_c) {
            print_message("Game Over!\n");
            exit(2);
        }
    }
    
    snake.insert(snake.begin(), {new_r, new_c});
    if (new_r == apple.first && new_c == apple.second) {
        generate_apple();
    } else {
        snake.pop_back();
    }
}

void play_game() {
    char key;
    while (true) {
        reset_board();
        add_snake_to_board();
        add_apple_to_board();
        draw_board();
        print_message("what do you want to do ('q' to quit):");
        
        std::cin >> key;
        if (key == 'q') {
            print_message("bye bye !\n");
            exit(0);
        } else if (key == 'i') {
            move_snake(-1, 0);
        } else if (key == 'k') {
            move_snake(1, 0);
        } else if (key == 'j') {
            move_snake(0, -1);
        } else if (key == 'l') {
            move_snake(0, 1);
        }
    }
}

int main() {
    init_snake();
    generate_apple();
    play_game();
    
    std::vector<std::string> letters;
    letters.push_back("abc");
    std::string s{"def"};
    letters.push_back(std::move(s));
    
    std::cout << "std::vector letters holds: ";
    for (auto&& e : letters)
        std::cout << std::quoted(e) << ' ';
    
    std::cout << "\nMoved-from string s holds: " << std::quoted(s) << '\n';
}