from PIL import Image
import numpy as np
img = Image.open('lenna.jpg')
img_array = np.array(img)
cropped_array = img_array[100:600, 100:600]
cropped_img = Image.fromarray(cropped_array)
cropped_img.show()
