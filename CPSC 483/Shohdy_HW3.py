# Import packages
import numpy as np
import pandas as pd

#Import the necessary module for Gaussian naive Bayes classifier
from sklearn.naive_bayes import GaussianNB

# Load the heart.csv dataset
data = pd.read_csv("heart.csv")

# Create a dataframe X containing chol and trestbps
X = data[['chol', 'trestbps']]

# Create dataframe y with output feature: target
y = data['target']

# Initialize a Gaussian naive Bayes model
model = GaussianNB()

# Fit the model
model.fit(X, y)

# Calculate the proportion of instances correctly classified
score = model.score(X, y)

# Print accuracy score 
print('Accuracy score for chol and trestbps is ', end="")
print('%.3f' % score)

# Create a dataframe X containing chol, trestbps, and fbs
X = data[['chol', 'trestbps', 'fbs']]

# Create dataframe y with output feature: target
y = data['target']

# Initialize a Gaussian naive Bayes model
model = GaussianNB()

# Fit the model
model.fit(X, y)

# Calculate the proportion of instances correctly classified
score = model.score(X, y)

# Print accuracy score
print('Accuracy score for chol, trestbps, and fbs is ', end="")
print('%.3f' % score)