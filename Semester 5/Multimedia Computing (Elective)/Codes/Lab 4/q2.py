import numpy as np
from PIL import Image
arr = np.random.randint(0,256,size=(400,400),dtype = np.uint8)
img = Image.fromarray(arr)
img.save('random_array.png')
img.show()