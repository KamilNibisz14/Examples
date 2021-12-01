import math

import numpy as np
import pandas as pd
import random

iris = pd.read_csv('iris.csv')
iris.iloc[0][0]


class KNN:
    @staticmethod
    def metric(sample, data_from_base):
        distance = 0
        for i in range(0, len(sample) - 1, 1):
            distance += (sample[i] - data_from_base.iloc[i]) ** 2
        return math.sqrt(distance)

    @staticmethod
    def clustering(sample, k, database, classes):
        distances = []
        x = database.copy()
        for i in range(0, 150, 1):
            distances.append(KNN.metric(sample, database.iloc[i]))
        for i in range(0, 150, 1):
            for j in iris.index:
                if distances[i] > distances[j]:
                    distances[i], distances[j] = distances[j], distances[i]
                    database.iloc[i], database.iloc[j] = database.iloc[j], database.iloc[i]
                    x.iloc[i], x.iloc[j] = x.iloc[j], x.iloc[i]
        for i in range(0, k, 1):
            classes[x.iloc[i][4]] += 1
        return max(classes, key=classes.get)


data = {'Sentosa': 0, 'Virginica': 0, 'Versicolor': 0}
out = [5.1, 3.5, 1.4, 0.2]
print(KNN.clustering(out, 3, iris, data))



