#!/usr/bin/env python3
import rospy
import os
import cv2
import calibrate as cal
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from opts import opts
from detectors.detector_factory import detector_factory
from centernet_ros.msg import BoundingBoxes
from centernet_ros.msg import BoundingBox

threshold = 0.25 #limite de score para empezar a considerar silla

def CenterNet_detection(img):
  #preprocess - recepcion y calibracion de la imagen
  bridge = CvBridge()
  cv_image = bridge.imgmsg_to_cv2(img, desired_encoding='passthrough') #'8UC3'
  #img_cal = cal.calibrate_images(cv_image.copy(), True, opt)

  #detection
  ret = detector.run(cv_image)

  detections = []

  msg = BoundingBoxes()
  msg.image_header = img.header

  #postprocess - mensaje
  for chair in ret['results'][57]:
      if chair[4] > threshold:
        msg.bounding_boxes.append(BoundingBox())
        msg.bounding_boxes[-1].Class = 'chair'
        msg.bounding_boxes[-1].probability = float(chair[4])
        msg.bounding_boxes[-1].xmin = int(chair[0])
        msg.bounding_boxes[-1].xmax = int(chair[2])
        msg.bounding_boxes[-1].ymin = int(chair[1])
        msg.bounding_boxes[-1].ymax = int(chair[3])
        msg.bounding_boxes[-1].depth = float(chair[5])

  pub.publish(msg)


rospy.init_node('Centernet', anonymous=True)

#init red
opt = opts().init()
os.environ['CUDA_VISIBLE_DEVICES'] = opt.gpus_str
Detector = detector_factory[opt.task]
detector = Detector(opt)

#init comunicacion
pub = rospy.Publisher('/detections', BoundingBoxes, queue_size=10)
sub = rospy.Subscriber('/device_0/sensor_1/Color_0/image/data', Image, CenterNet_detection)
rospy.spin()
  

