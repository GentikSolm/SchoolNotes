# 2/2/21 KNN model of different wheat seeds
from sklearn.model_selection import train_test_split
import pandas as pd
from matplotlib import cm
from pandas.plotting import scatter_matrix
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d   # must keep
from sklearn.neighbors import KNeighborsClassifier
import numpy as np
#reading in the seeds data set and spliting it into training sets
seeds = pd.read_csv('seeds_dataset.csv')
seedNames = dict(zip(seeds.seedType.unique(),[ "Kama", "Rosa", "Canadian"]))

X = seeds[["area","perimeter","compactness","lengthOfKernel","widthOfKernel","asymmetryCoefficient",]]
y = seeds["seedType"]
    # there are 70 of each class, Kama, Rosa and Canadian for a total of 3 classes
    # with equal class distrobution
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0, test_size = .25, train_size = .75)
    # We are partitioning the data here so that the test size is 25% of the data and the training size
    # is 75% of the data. This gives us a decent test group with enough data to get
    #  reliable statistics on accuracy.

#2D plot or scatter plot
cmap = cm.get_cmap('gnuplot')
scatter = scatter_matrix(X_train, c= y_train, marker = 'o', s=40, hist_kwds={'bins':15}, figsize=(9,9), cmap=cmap)

#3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
ax.scatter(X_train['area'], X_train['asymmetryCoefficient'], X_train['compactness'], c = y_train, marker = '$f$', s=100)
ax.set_xlabel('area')
ax.set_ylabel('asymmetryCoefficient')
ax.set_zlabel('compactness')
plt.show()

#kNN set up
knn = KNeighborsClassifier(n_neighbors = 5, weights = 'distance', metric = 'minkowski', p = 2)
    #When minkowski has p set as 2, this is equivilant to euclidian distance
knn.fit(X_train, y_train)
actual = [0,0,0]
predict = [0,0,0]
index = X_test.index
number_of_rows = len(index)
for i in range(0,number_of_rows-1):
    thisTest = X_test.iloc[[i]].values
    predict[knn.predict(thisTest)[0]-1]+=1
    actual[y_test.iloc[[i]].values[0]-1]+=1
    # actual[y_test.iloc(i)[0]-1] += 1
    # print(i)
print("Predicted:")
for i in range(3):
    print(seedNames[i+1], predict[i])
print("\nActual:")
for i in range(3):
    print(seedNames[i+1], actual[i])

knn.score(X_test, y_test)

#Showing accuracy according to n_neighnors
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
plt.show()

#Showing the training set proportion
t = [0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2]
knn = KNeighborsClassifier(n_neighbors=5, weights = 'distance', metric = 'minkowski', p = 2)
plt.figure()
for s in t:
    scores = []
    for i in range(1, 1000):
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1-s)
        knn.fit(X_train, y_train)
        scores.append(knn.score(X_test, y_test))
    plt.plot(s, np.mean(scores), 'bo')
#Showing plots
plt.xlabel('Training set proportion (%)')
plt.ylabel('accuracy')
plt.show()
#...
