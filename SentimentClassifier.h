#ifndef SENTIMENTCLASSIFIER_H
#define SENTIMENTCLASSIFIER_H

#include <unordered_map>
#include "DSString.h"

class SentimentClassifier {
private:
    // Maps to store word counts for positive and negative sentiments
    std::unordered_map<DSString, int> positiveWordCounts;
    std::unordered_map<DSString, int> negativeWordCounts;

    // Counters for the total number of positive and negative tweets
    int totalPositiveTweets = 0;
    int totalNegativeTweets = 0;

public:
    // Trains the classifier using the specified training data file
    void train(const char* trainingDataFile);

    // Predicts sentiments for a test dataset and writes the results to an output file
    void predict(const char* testingDataFile, const char* outputFile);

    // Evaluates the classifier's predictions by comparing them with ground truth
    void evaluatePredictions(const char* predictionsFile, const char* groundTruthFile, const char* accuracyFile);
};

#endif
