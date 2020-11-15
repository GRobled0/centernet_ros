# Requisitos

En principio he construido el paquete con rosbuild en vez de catkin.
Es necesario el paquete CV_Bridge para poder recibir una imagen como mensaje de ROS y transformarla en una imagen OpenCV.
También he estado utilizando python 3.

# Modelo

El archivo .pth que contiene la red pesa un poco más que el máximo recomendado por github así que si hubiese algún problema añado un link a drive donde descargarlo, habría que guardarlo en la carpeta "modelos" dentro del directorio "centernet_ros".

https://drive.google.com/file/d/1UoyYRo-547K34rzCRsOHVzETdzbX-mJA/view?usp=sharing


# Uso

He retirado los scripts dedicados a entrenamiento y carga de datasets para minimizar posibles problemas de compatibilidad. En las opciones (opts.py) he dispuesto los defaults para que para correr el detector sólo sea necesario escribir el siguiente comando en el terminal.

~~~
rosrun centernet_ros detector.py
~~~

# Input/Output

El modulo se suscribe esperando una imagen a '/device_0/sensor_1/Color_0/image/data' y publica una versión modificada del mensaje BoundingBoxes donde se le añade la profundidad a la que se encuentra la bounding box en el tópico '/detections'.
