from sklearn.model_selection import train_test_split
from sklearn.preprocessing import scale
from sklearn.datasets import load_breast_cancer
from sklearn.neural_network import MLPClassifier
import pandas as pd
from pandas.plotting import scatter_matrix
from matplotlib import cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d   # must keep
import numpy as np

ledger = open("Scores.txt", "w")

X, y = load_breast_cancer(return_X_y=True, as_frame=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=1)
# Splits the data


# Plotting of data
totalScores = []
for activation in ['logistic', 'relu', 'tanh', 'identity']:
    for decent in ['lbfgs', 'sgd', 'adam']:
        for alpha in [.0001, .001, .01, .1]:
            for i in range(5, 31, 5):
                neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i))
                neural.fit(X_train, y_train)
                score = neural.score(X_test, y_test)
                totalScores.append([score, [activation, decent, alpha, i]])
                for j in range(5, 31, 5):
                    neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i, j))
                    neural.fit(X_train, y_train)
                    score = neural.score(X_test, y_test)
                    totalScores.append([score, [activation, decent, alpha, i, j]])
                    for k in range(5, 31, 5):
                        neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i, j, k))
                        neural.fit(X_train, y_train)
                        score = neural.score(X_test, y_test)
                        totalScores.append([score, [activation, decent, alpha, i, j, k]])
print("Unscaled: ")
ledger.write("Unscaled:\n")
sotrtedScores = sorted(totalScores, key=lambda x: x[0], reverse=True)
for i in range(10):
    print(sotrtedScores[i])
    ledger.write(str(sotrtedScores[i]))
    ledger.write('\n')
ledger.write('\n')
for i in range(1, 11):
    print(sotrtedScores[-i])
    ledger.write(str(sotrtedScores[-i]))
    ledger.write('\n')
X, y = load_breast_cancer(return_X_y=True)
scale(X)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=1)
totalScoresScaled = []
for activation in ['logistic', 'relu', 'tanh', 'identity']:
    for decent in ['lbfgs', 'sgd', 'adam']:
        for alpha in [.0001, .001, .01, .1]:
            for i in range(5, 31, 5):
                neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i))
                neural.fit(X_train, y_train)
                score = neural.score(X_test, y_test)
                totalScoresScaled.append([score, [activation, decent, alpha, i]])
                for j in range(5, 31, 5):
                    neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i, j))
                    neural.fit(X_train, y_train)
                    score = neural.score(X_test, y_test)
                    totalScoresScaled.append([score, [activation, decent, alpha, i, j]])
                    for k in range(5, 31, 5):
                        neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i, j, k))
                        neural.fit(X_train, y_train)
                        score = neural.score(X_test, y_test)
                        totalScoresScaled.append([score, [activation, decent, alpha, i, j, k]])
print("\nScaled: ")
ledger.write("\nScaled:\n")
sotrtedScores = sorted(totalScoresScaled, key=lambda x: x[0], reverse=True)
for i in range(10):
    print(sotrtedScores[i])
    ledger.write(str(sotrtedScores[i]))
    ledger.write('\n')
ledger.write('\n')
for i in range(1, 11):
    print(sotrtedScores[-i])
    ledger.write(str(sotrtedScores[-i]))
    ledger.write('\n')
ledger.close()
