#include <iostream>
#include <string>

// Movie structure with additional members for production costs and first-year revenues
struct Movie {
    std::string title;
    std::string director;
    int releaseYear;
    int runningTime;
    double productionCosts; // Additional member for production costs
    double firstYearRevenues; // Additional member for first-year revenues
};

// Function to display movie data including title, director, release year, running time,
// and first year's profit or loss.
void displayMovieData(const Movie& movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Director: " << movie.director << std::endl;
    std::cout << "Release Year: " << movie.releaseYear << std::endl;
    std::cout << "Running Time: " << movie.runningTime << " minutes" << std::endl;

    // Calculate first year's profit or loss
    double profitLoss = movie.firstYearRevenues - movie.productionCosts;

    std::cout << "First Year's Profit/Loss: $" << profitLoss << std::endl;
}

int main() {
    // Example usage
    Movie myMovie;

    // Assign values to members
    myMovie.title = "The Great Movie";
    myMovie.director = "John Director";
    myMovie.releaseYear = 2022;
    myMovie.runningTime = 120;
    myMovie.productionCosts = 1000000.0; // Example production costs
    myMovie.firstYearRevenues = 1500000.0; // Example first-year revenues

    // Display movie data
    displayMovieData(myMovie);

    return 0;
}
