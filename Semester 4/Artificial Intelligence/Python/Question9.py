# 9. Write a Program to Implement Naïve Bayes Algorithm using Python.

import numpy as np

class NaiveBayes:
    def fit(self, X, y):
        self.X = X
        self.y = y
        self.classes = np.unique(y)
        self.parameters = {}
        for c in self.classes:
            X_c = X[y == c]
            self.parameters[c] = {
                'mean': X_c.mean(axis=0),
                'std': X_c.std(axis=0) + 1e-4 
            }

    def _likelihood(self, x, mean, std):
        return np.exp(-((x - mean) ** 2) / (2 * std ** 2)) / (np.sqrt(2 * np.pi) * std)

    def _prior(self, c):
        return np.mean(self.y == c)

    def _posterior(self, x):
        posteriors = []
        for c in self.classes:
            likelihood = np.sum(np.log(self._likelihood(x, self.parameters[c]['mean'], self.parameters[c]['std'])))
            prior = np.log(self._prior(c))
            posterior = likelihood + prior
            posteriors.append(posterior)
        return self.classes[np.argmax(posteriors)]

    def predict(self, X):
        y_pred = [self._posterior(x) for x in X]
        return np.array(y_pred)

X_train = np.array([[1, 1], [2, 2], [3, 3], [4, 4], [5, 5], [6, 6]])
y_train = np.array([0, 0, 0, 1, 1, 1])

model = NaiveBayes()
model.fit(X_train, y_train)

X_test = np.array([[1.5, 1.5], [5.5, 5.5]])
y_pred = model.predict(X_test)

print("Predictions:", y_pred)
