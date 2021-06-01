from sklearn.model_selection import train_test_split
from sklearn.preprocessing import scale
from sklearn.datasets import load_breast_cancer
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import plot_confusion_matrix
import pandas as pd
from pandas.plotting import scatter_matrix
from matplotlib import cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d   # must keep
import numpy as np


myList = [[0.972027972027972, ['relu', 'lbfgs', 0.0001, 15, 15, 0]], [0.972027972027972, ['relu', 'lbfgs', 0.0001, 20, 30, 30]], [0.972027972027972, ['relu', 'lbfgs', 0.0001, 30, 15, 15]], [0.972027972027972, ['relu', 'lbfgs', 0.001, 15, 5, 0]], [0.972027972027972, ['relu', 'lbfgs', 0.001, 20, 15, 25]], [0.972027972027972, ['relu', 'lbfgs', 0.01, 5, 30, 20]], [0.972027972027972, ['relu', 'lbfgs', 0.01, 25, 20, 10]], [0.972027972027972, ['relu', 'lbfgs', 0.1, 20, 25, 5]], [0.972027972027972, ['relu', 'lbfgs', 0.1, 20, 30, 15]], [0.972027972027972, ['relu', 'lbfgs', 0.1, 30, 10, 20]]]
# myList is a list of the top 10 fits
X, y = load_breast_cancer(return_X_y=True, as_frame=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=2)
cmap = cm.get_cmap('gnuplot')
scatter = scatter_matrix(X_train, c= y_train, marker = 'o', s=40, hist_kwds={'bins':15}, figsize=(9,9), cmap=cmap)
plt.show()
for i in myList:
    if i[1][5] == 0:
        neural = MLPClassifier(random_state = 1, activation=i[1][0], solver=i[1][1], alpha=i[1][2], hidden_layer_sizes=(i[1][3], i[1][4]))
    else:
        neural = MLPClassifier(random_state = 1, activation=i[1][0], solver=i[1][1], alpha=i[1][2], hidden_layer_sizes=(i[1][3], i[1][4], i[1][5]))
    neural.fit(X_train, y_train)
    score = neural.score(X_test, y_test)
    plot_confusion_matrix(neural, X_test, y_test, display_labels=["B", "M"])
    plt.title(i)
    plt.show()
