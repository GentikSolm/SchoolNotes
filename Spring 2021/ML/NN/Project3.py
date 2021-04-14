from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import load_breast_cancer
from sklearn.neural_network import MLPClassifier
import pandas as pd
from pandas.plotting import scatter_matrix
from matplotlib import cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d   # must keep
import numpy as np

X, y = load_breast_cancer(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=1)
# Splits the data

cmap = cm.get_cmap('gnuplot')
scatter = scatter_matrix(X_train, c= y_train, marker = 'o', s=40, hist_kwds={'bins':15}, figsize=(9,9), cmap=cmap)
# Plotting of data
totalScores = []
for activation in ['logistic', 'relu', 'tanh', 'identity']:
    for decent in ['lbfgs', 'sgd', 'adam']:
        for i in range(5, 100, 5):
            for j in range(5, 100, 5):
                for k in range(5, 100, 5):
                    for alpha in [.0001, .001, .01, .1]:
                        neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i, j, k))
                        neural.fit(X_train, y_train)
                        score = neural.score(X_test, y_test)
                        totalScores.append([score, [activation, decent, alpha, i, j, k]])
print("Unscaled: ")
sorted(totalScores, key=lambda x: x[0])
for i in range(10):
    print(totalScores[i])

X, y = load_breast_cancer(return_X_y=True)
scale(X)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=1)
totalScoresScaled = []
for activation in ['logistic', 'relu', 'tanh', 'identity']:
    for decent in ['lbfgs', 'sgd', 'adam']:
        for i in range(5, 100, 5):
            for j in range(5, 100, 5):
                for k in range(5, 100, 5):
                    for alpha in [.0001, .001, .01, .1]:
                        neural = MLPClassifier(random_state = 1, activation=activation, solver=decent, alpha=alpha, hidden_layer_sizes=(i, j, k))
                        neural.fit(X_train, y_train)
                        score = neural.score(X_test, y_test)
                        totalScoresScaled.append([score, [activation, decent, alpha, i, j, k]])
print("\nScaled: ")
sorted(totalScoresScaled, key=lambda x: x[0])
for i in range(10):
    print(totalScoresScaled[i])
