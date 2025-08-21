#!/usr/bin/env python3
import os

folder = "animation"

for f in os.listdir(folder):
    if f.endswith(".xpm"):
        path = os.path.join(folder, f)
        with open(path, "r") as file:
            lines = file.readlines()
            for line in lines:
                line = line.strip()
                # Look for the line starting with a quote
                if line.startswith('"'):
                    # Remove quotes and split by spaces
                    content = line.strip('"')
                    parts = content.split()
                    if len(parts) >= 2:
                        try:
                            width = int(parts[0])
                            height = int(parts[1])
                            print(f"{f}: width={width}, height={height}")
                        except ValueError:
                            print(f"{f}: Could not parse dimensions in line: {line}")
                    break


امين المشرفي
محسن ازبيدة
جمال الخشين
محمد العوام
الهواري زكرياء
المهدي نعمان
اسامة قوتي
الحفظ
المراجعة
تتبع الحفظ  و المراجعة المجموعة 5