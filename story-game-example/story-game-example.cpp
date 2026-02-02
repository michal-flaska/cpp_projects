// CLI Story Game - Template
// Created by Matyáš Hájek
// github.com/maty7253

#include <iostream>      // For input/output operations
#include <string>        // For std::string
#include <unordered_map> // For mapping choices to next scenes

// Structure representing a single story scene
struct Scene
{
        std::string description;               // Text shown to the player in this scene
        std::unordered_map<char, int> choices; // Map: input character -> next scene ID
};

// The game class handles the game logic and state
class Game
{
private:
        std::unordered_map<int, Scene> scenes; // Collection of all scenes indexed by scene ID
        int currentScene;                      // ID of the current scene the player is in

        // Function to display the current scene description and available choices
        void displayScene()
        {
                // Get the current scene object from the scenes map
                const auto &scene = scenes[currentScene];

                // Print the scene description
                std::cout << scene.description << "\n\n";

                // Print all available choices for this scene
                std::cout << "Choices:\n";
                for (const auto &choice : scene.choices)
                {
                        // choice.first = input key (e.g. 'L'), choice.second = next scene ID (e.g. 2)
                        std::cout << " [" << choice.first << "] -> Scene " << choice.second << "\n";
                }
                std::cout << "\nEnter choice: ";
        }

        // Function to get player's input and move to the next scene based on the input
        void processInput()
        {
                char input;        // Variable to store player's input character
                std::cin >> input; // Read input from the console

                // Reference to the choices map of the current scene
                auto &choices = scenes[currentScene].choices;

                // Check if player's input matches one of the valid choices
                if (choices.find(input) != choices.end())
                {
                        // Valid choice: update currentScene to the next scene ID mapped to input
                        currentScene = choices[input];
                }
                else
                {
                        // Invalid input: notify player and do not change scene
                        std::cout << "Invalid choice. Try again.\n";
                }
        }

public:
        // Constructor - initialize game scenes and starting scene ID
        Game() : currentScene(1)
        {
                // Define each scene by assigning a Scene struct to the scenes map using an ID

                // Scene 1: Starting room with two doors
                scenes[1] = Scene{
                    "You are in a dark room. There is a door to your [L]eft and [R]ight.",
                    {{'L', 2}, {'R', 3}} // Press 'L' to go to scene 2, 'R' to scene 3
                };

                // Scene 2: Treasure chest scene
                scenes[2] = Scene{
                    "You find a treasure chest. You can [O]pen it or go [B]ack.",
                    {{'O', 4}, {'B', 1}} // 'O' opens chest -> scene 4, 'B' goes back -> scene 1
                };

                // Scene 3: Monster encounter
                scenes[3] = Scene{
                    "You encounter a monster. You can [F]ight or [R]un back.",
                    {{'F', 5}, {'R', 1}} // 'F' fight -> scene 5, 'R' run back -> scene 1
                };

                // Scene 4: Win scene (no choices)
                scenes[4] = Scene{
                    "You found gold! You win.\nGame Over.",
                    {} // No choices, game ends here
                };

                // Scene 5: Lose scene (no choices)
                scenes[5] = Scene{
                    "The monster defeated you.\nGame Over.",
                    {} // No choices, game ends here
                };
        }

        // Main game loop - run until no choices are left (end of game)
        void run()
        {
                while (true)
                {
                        displayScene(); // Show current scene text and choices

                        // If no choices available, end game loop
                        if (scenes[currentScene].choices.empty())
                                break;

                        processInput(); // Get player input and change scene
                }
        }
};

int main()
{
        Game game;  // Create a Game object (runs constructor)
        game.run(); // Start the game loop
        return 0;   // End program when game ends
}
