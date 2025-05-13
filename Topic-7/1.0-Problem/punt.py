#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 29 10:59:12 2023

@author: quitus
"""

from math import sqrt

class Punt:
	"""Punt"""
	def __init__(self, x=0, y=0):
		self._x = x
		self._y = y

	def get_x(self):
		return self._x

	def get_y(self):
		return self._y

	def set_x(self, x):
		self._x = x

	def set_y(self, y):
		self._y = y

	def __add__(self, p):
		return Punt(self._x + p.get_x(), self._y + p.get_y())

	def __sub__(self, p):
	    return Punt (self._x - p.get_x(), self._y - p.get_y())

	def l2(self, p):
	    return ((self._x-p.get_x())**2 + (self._y - p.get_y())**2)**(1/2)

	def __str__(self):
		return f"Punt({self._x}, {self._y})"


if __name__ == '__main__':
	from math import sqrt
	p0 = Punt(5, 5)
	p1 = Punt(1, 1)

	p2 = p0 - p1

	if p2 is not None:
		if p2.get_x() == 4 and p2.get_y() == 4:	
			grade = 5
			print(f"Comment ==> Test resta correcte")
		else:
			print(f"Comment ==> p2 = {p2}. Esperat: Punt(4, 4)")
	else:
		print(f"Comment ==> p2 = {p2}. Esperat: Punt(4, 4)")

	if p0.l2(p1) == sqrt(32):
		grade += 5
		print(f"Comment ==> Test distancia L2 correcte")
	else:
		print(f"Comment ==> Test distancia L2 incorrecta.\n Hint: sqrt(dx** 2 + dy ** 2)")