#Requisitos

En principio he construido el paquete con rosbuild en vez de catkin.
Es necesario el paquete CV_Bridge para poder recibir una imagen como mensaje de ROS y transformarla en una imagen OpenCV.
También he estado utilizando python 3.


#Uso

He retirado los scripts dedicados a entrenamiento y carga de datasets para minimizar posibles problemas de compatibilidad. En las opciones (opts.py) he dispuesto los defaults para que para correr el detector sólo sea necesario escribir el siguiente comando en el terminal.

~~~
rosrun centernet_ros detector.py
~~~

#Input/Output

El modulo se suscribe esperando una imagen a '/device_0/sensor_1/Color_0/image/data' y publica una versión modificada del mensaje BoundingBoxes donde se le añade la profundidad a la que se encuentra la bounding box en el tópico '/detections'.
