import matplotlib.pyplot as plt
from PIL import Image

img = Image.open("lenna.jpg")

img = img.convert('L')

pixels = img.getdata()

plt.hist(pixels, bins=256, range=(0, 255), alpha=0.8, color='black')
plt.xlabel("Pixel value")
plt.ylabel("Frequency")
plt.title("Histogram of Lenna.jpg")
plt.show()
