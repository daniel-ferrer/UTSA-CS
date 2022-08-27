from csv import reader
from pyspark import SparkContext

sc = SparkContext(appName="hw2")
sc.setLogLevel("ERROR")