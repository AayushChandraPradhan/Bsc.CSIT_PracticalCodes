# 10. Write a Program to Implement Back propagation Algorithm using Python

import numpy as np

# Activation functions
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return sigmoid(x) * (1 - sigmoid(x))

# Neural network class
class NeuralNetwork:
    def __init__(self, input_nodes, hidden_nodes, output_nodes, learning_rate):
        # Initialize weights with random values
        self.weights_ih = np.random.rand(hidden_nodes, input_nodes) - 0.5
        self.weights_ho = np.random.rand(output_nodes, hidden_nodes) - 0.5
        self.learning_rate = learning_rate

    def feedforward(self, inputs):
        hidden_inputs = np.dot(self.weights_ih, inputs)
        hidden_outputs = sigmoid(hidden_inputs)
        output_inputs = np.dot(self.weights_ho, hidden_outputs)
        output_outputs = sigmoid(output_inputs)
        return output_outputs

    def backpropagation(self, inputs, targets):
      outputs = self.feedforward(inputs)
      output_errors = targets - outputs
      hidden_errors = np.dot(self.weights_ho.T, output_errors)
      
      # Calculate hidden_outputs
      hidden_outputs = self.sigmoid(np.dot(self.weights_ih, inputs))
  
      # Update weights
      self.weights_ho += self.learning_rate * np.dot((output_errors * self.sigmoid_derivative(outputs)), np.transpose(hidden_outputs))
      self.weights_ih += self.learning_rate * np.dot((hidden_errors * self.sigmoid_derivative(hidden_outputs)), np.transpose(inputs))

    def train(self, inputs, targets, epochs):
        for _ in range(epochs):
            for i in range(len(inputs)):
                self.backpropagation(inputs[i], targets[i])

# Example usage
# Create a neural network with more hidden nodes (optional)
nn = NeuralNetwork(2, 4, 1, 0.1)  # Smaller learning rate

# Ensure NumPy arrays for inputs and targets (XOR problem)
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
targets = np.array([[0], [1], [1], [0]])

# Train the neural network with more epochs
nn.train(inputs, targets, 50000)  # Increased epochs

# Test the neural network
print(nn.feedforward(np.array([0, 1])))  # Should be closer to 1 for XOR
