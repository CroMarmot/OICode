#!/usr/bin/env python3
import os
from PIL import Image, ImageDraw

result_folder = "../ProjectEulerTimeCost/"
# size of image
blocksz = 100
n = 10
scale = 10
canvas = (n*blocksz, n*blocksz)

# 最大题目号
maxpid = 802

imgroup = []


def draw_time():
    for t in range(0, maxpid+1, n*n):
        im = Image.new('RGBA', canvas, (255, 255, 255, 255))
        draw = ImageDraw.Draw(im)

        for i in range(n):
            for j in range(n):
                x1 = i*blocksz
                y1 = j*blocksz
                x2 = (i+1)*blocksz-1
                y2 = (j+1)*blocksz-1
                draw.rectangle([x1, y1, x2, y2], fill=(0, 0, 0, 63), outline=(0, 0, 0, 127))

        imgroup.append(im)

    for f in os.listdir(result_folder):
        p = os.path.join(result_folder, f)
        if os.path.isfile(p) and f.endswith(".time.md"):
            pid = int(f.split('.')[0][1:])
            idx = (pid-1)//(n*n)
            j = ((pid-1) % (n*n))//n
            i = (pid-1) % n
            with open(p, "r") as o:
                w = o.read().strip()
                t = float(w)
                if t > 60:
                    fill = (255, 0, 0, 255)
                else:
                    fill = (0, 255, 0, 255)
            x1 = i*blocksz
            y1 = j*blocksz
            x2 = (i+1)*blocksz-1
            y2 = (j+1)*blocksz-1
            draw = ImageDraw.Draw(imgroup[idx])
            draw.rectangle([x1, y1, x2, y2], fill=fill, outline=(0, 0, 0, 127))

    for i in range(len(imgroup)):
        t = (i+1)*n*n
        im = imgroup[i]
        # im.show()
        im.thumbnail((canvas[0]/scale, canvas[1]/scale))
        im.save(os.path.join(result_folder, f"{t}.png"))


if __name__ == '__main__':
    draw_time()
