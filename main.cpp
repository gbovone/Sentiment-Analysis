#include <iostream>
#include "SentimentClassifier.h"

int main(int argc, char** argv)
{
    // Check if the number of command-line arguments is correct
    if (argc != 6) {
        // Display usage information if arguments are incorrect
        std::cerr << "Usage: ./Assignment2_sentiment trainingDataFile testingDataFile groundTruthFile predictionsFile accuracyFile" << std::endl;
        return 1; 
    }

    SentimentClassifier classifier;

    // Train the classifier using the provided training data file
    classifier.train(argv[1]);

    // Predict sentiments for the test data and write the predictions to the specified file
    classifier.predict(argv[2], argv[4]);

    // Evaluate the predictions against the ground truth and write accuracy results to the specified file
    classifier.evaluatePredictions(argv[4], argv[3], argv[5]);

    return 0; 
}
