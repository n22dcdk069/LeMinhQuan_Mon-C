#include <iostream>
#include <string>

// Define the MovieData structure
struct MovieData {
    std::string title;
    std::string director;
    int yearReleased;
    int runningTime; // in minutes
};

// Function to display information about a movie
void displayMovieInfo(const MovieData& movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Director: " << movie.director << std::endl;
    std::cout << "Year Released: " << movie.yearReleased << std::endl;
    std::cout << "Running Time: " << movie.runningTime << " minutes" << std::endl;
    std::cout << std::endl;
}

int main() {
    // Create two MovieData variables and store values in their members
    MovieData movie1 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142};
    MovieData movie2 = {"Inception", "Christopher Nolan", 2010, 148};

    // Display information about each movie
    std::cout << "Movie 1 Information:" << std::endl;
    displayMovieInfo(movie1);

    std::cout << "Movie 2 Information:" << std::endl;
    displayMovieInfo(movie2);

    return 0;
}
