# -*- coding: utf-8 -*-
"""
Created on Mon Mar  1 12:56:29 2021

@author: nickk
"""

# 13 atributes, 2 classes.
# 165 - 1
# 138 - 0
from pandas.plotting import scatter_matrix
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import cm
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import scale
from sklearn.metrics import plot_confusion_matrix
import numpy as np
from sklearn.svm import SVC


heartData = pd.read_csv("heart.csv")
# create a mapping from fruit label value to fruit name to make results easier to interpret
lookup_heart = dict(zip(heartData.target.unique(), [True, False]))
print(lookup_heart)
print("165 True, 138 False.")

X = heartData[['age', 'sex', 'cp', 'trestbps', 'chol', 'fbs', 'restecg', 'thalach', 'exang', 'oldpeak', 'slope', 'ca', 'thal']]
y = heartData['target']
print("13 total features, 2 classes.")

X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0, test_size = .25, train_size = .75)
print("Using 75% of data for training, 25% for testing.")
#start subplot matrix of each feature vs other features
cmap = cm.get_cmap('gnuplot')
scatter = scatter_matrix(X_train, c= y_train, marker = 'o', s=40, hist_kwds={'bins':14}, figsize=(9,9), cmap=cmap)
plt.show()

#3d plot of select features
#3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
ax.scatter(X_train['trestbps'], X_train['age'], X_train['chol'], c = y_train, s=100)
ax.set_xlabel('trestbps')
ax.set_ylabel('age')
ax.set_zlabel('chol')
plt.show()

X = scale(X)
# We need to resplit and scale our data after giving visual representation.
knnScores = []
lrScores = []
svmScores = []
for i in range(1, 50):
    X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=i, test_size = .25, train_size = .75)

    # print("--------")
    # print()
    #First, knn:
    k_range = range(1, 100)
    scores = []
    for k in k_range:
        knn = KNeighborsClassifier(n_neighbors = k, weights = 'distance', metric = 'minkowski', p = 2)
        knn.fit(X_train, y_train)
        scores.append(knn.score(X_test, y_test))
    #Plotting
    plt.figure()
    plt.xlabel('k')
    plt.ylabel('accuracy')
    plt.plot(k_range, scores)
    plt.xticks([0, 25, 50, 75, 100])
    #Here we can see 8 yeilds the best ammount of accuracy.
    plt.show()

    knn = KNeighborsClassifier(n_neighbors = 8, weights = 'distance', metric = 'minkowski', p = 2)
    knn.fit(X_train, y_train)

    plot_confusion_matrix(knn, X_test, y_test)
    score = knn.score(X_test, y_test) * 100
    knnScores.append(score)
    plt.title("Knn Confusion Matrix, {:.2f}% accuracy".format(score))
    plt.show()
    # print("KNN Test set score: {:.2f}".format(score))

    #2nd, Logistic Regression:
    lr = LogisticRegression(random_state=0)
    lr.fit(X_train, y_train)
    # print("lr.coef_: {}".format(lr.coef_))
    # print("lr.intercept_: {}".format(lr.intercept_))
    #print("LR Training set score: {:.2f}".format(lr.score(X_train, y_train)))
    plot_confusion_matrix(lr, X_test, y_test)
    score = lr.score(X_test, y_test) * 100
    lrScores.append(score)
    # print("Logistic Regression Test set score: {:.2f}".format(score))
    plt.title("Logistic Regression Confusion Matrix, {:.2f}% accuracy".format(score))
    plt.show()

    #3rd, SVM
    svc = SVC(C=100, kernel="linear", random_state=0, tol=1e-4)
    svc.fit(X_train, y_train)
    #print("Linear SVM Training set score: {:.2f}%".format(100*svc.score(X_train, y_train)))
    plot_confusion_matrix(svc, X_test, y_test)
    score = svc.score(X_test, y_test) * 100
    svmScores.append(score)
    # print("Linear SVM Test set score: {:.2f}%".format(score))
    plt.title("Linear SVM Confusion Matrix, {:.2f}% accuracy".format(score))
    plt.show()
    # print()
    plt.close('all')
npKnn = np.array(knnScores)
npLr = np.array(lrScores)
npSvm = np.array(svmScores)
print("Model    Min         Mean        Max")
print("Knn      {:.2f}%     {:.2f}%     {:.2f}% at {}".format(np.amin(npKnn),np.mean(npKnn),np.amax(npKnn), np.argmax(npKnn)))
print("Lr       {:.2f}%     {:.2f}%     {:.2f}% at {}".format(np.amin(npLr),np.mean(npLr),np.amax(npLr), np.argmax(npLr)))
print("Svm      {:.2f}%     {:.2f}%     {:.2f}% at {}".format(np.amin(npSvm),np.mean(npSvm),np.amax(npSvm), np.argmax(npSvm)))
