# Write a Program to Implement Genetics algorithm using Python

import random
import string

def generate_random_string(length):
  """Generates a random string of the specified length using letters and spaces."""
  return ''.join(random.choice(string.ascii_letters + ' ') for _ in range(length))

def initial_population(population_size, target_string_length):
  """Creates an initial population of random strings."""
  return [generate_random_string(target_string_length) for _ in range(population_size)]

def fitness(target_string, test_string):
  """Calculates the fitness score of a string based on its similarity to the target string."""
  return sum(1 for t, s in zip(target_string, test_string) if t == s)

def selection(population, target_string):
  """Selects the two fittest strings from the population based on their fitness score."""
  return sorted(population, key=lambda x: fitness(target_string, x), reverse=True)[:2]

def crossover(parent1, parent2):
  """Performs crossover between two parent strings to create two children."""
  crossover_point = random.randint(1, len(parent1) - 1)
  child1 = parent1[:crossover_point] + parent2[crossover_point:]
  child2 = parent2[:crossover_point] + parent1[crossover_point:]
  return child1, child2

def mutation(child, mutation_rate):
  """Mutates characters in the child string with a certain probability."""
  return ''.join(random.choice(string.ascii_letters + ' ') if random.random() < mutation_rate else c for c in child)

def genetic_algorithm(target_string, population_size=10, mutation_rate=0.01, max_generations=100):
  """Implements the genetic algorithm to find the target string."""
  population = initial_population(population_size, len(target_string))
  generation = 1
  while True:
    parents = selection(population, target_string)
    if fitness(target_string, parents[0]) == len(target_string):
      return parents[0], generation
    children = crossover(parents[0], parents[1])
    population = [mutation(child, mutation_rate) for child in children]
    generation += 1

    if generation > max_generations:
      print(f"Maximum generations reached ({max_generations}). Not found.")
      return None, generation

target = "Hello, World!"
result, generations = genetic_algorithm(target)
print(f"Found solution '{result}' in {generations} generations.")

