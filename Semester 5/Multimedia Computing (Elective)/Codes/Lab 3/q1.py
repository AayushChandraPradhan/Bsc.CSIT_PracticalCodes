from PIL import Image
import os
jpg_image_path = 'lenna.jpg'
image = Image.open(jpg_image_path)
png_image_path = 'lenna.png'
tif_image_path = 'lenna.tif'
image.save(png_image_path, 'PNG')
image.save(tif_image_path, 'TIFF')
jpg_size = os.path.getsize(jpg_image_path)
png_size = os.path.getsize(png_image_path)
tif_size = os.path.getsize(tif_image_path)
print(f"Disk size of JPG file: {jpg_size} bytes")
print(f"Disk size of PNG file: {png_size} bytes")
print(f"Disk size of TIFF file: {tif_size} bytes")
with open(jpg_image_path, 'rb') as f:
    actual_jpg_size = len(f.read())
print(f"Actual size of JPG file: {actual_jpg_size} bytes")
print("Khusboo Karki")

