from django.shortcuts import render
from plotly.offline import plot
from plotly.graph_objs import Scatter
import pymysql

db = pymysql.connect("localhost","root","","jeetu" )
cursor = db.cursor()

def graphjeetu2(request):
	query = "SELECT * FROM datepow"
	cursor.execute(query)

	rows = cursor.fetchall()

	dates = []
	values = []
	for row in rows:
		dates.append(row[0])
		values.append(row[1])

	plot_div = plot([Scatter(x=dates, y= values, mode = 'lines', name= 'test', opacity=0.8, marker_color='green')], output_type='div')

	return render(request, "graph.html", context= {'plot_div': plot_div})