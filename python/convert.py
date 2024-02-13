# the purpose of the functions is converting WGS 84 to cartesian 
# and finding apsis and ordinat value (x, y) of a point as our own local orjin

from pyproj import Proj, transform

def convert(latitude, longitude):

    wgs84 = Proj(init='epsg:4326')
    cartesian = Proj(init='epsg:3857')

    x, y= transform(wgs84, cartesian, longitude, latitude)

    return x, y

def orjin(lat0, lon0, lat, lon):
    x0, y0 = convert(lat0, lon0)
    x, y = convert(lat, lon)

    return x - x0, y - y0


