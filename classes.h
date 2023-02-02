class GravitySensor {

  public:

    void begin() {
      pinMode(YAxis , INPUT);
      pinMode(XAxis , INPUT);
    }

};

class LightSensor {

  public:

    void begin() {
      pinMode(LightPin, INPUT);
    }

};



class TouchSensor {

  public:

    void begin() {
      pinMode(TouchPin1, INPUT);
      pinMode(TouchPin2, INPUT);
      pinMode(TouchPin3, INPUT);
      pinMode(TouchPin4, INPUT);
    }

    boolean Touch1() {
      boolean TouchState1 = map(digitalRead(TouchPin1), HIGH, LOW, true, false);
      return TouchState1;
    }

    boolean Touch2() {
      boolean TouchState2 = map(digitalRead(TouchPin2), HIGH, LOW, true, false);
      return TouchState2;
    }

    boolean Touch3() {
      boolean TouchState3 = map(digitalRead(TouchPin3), HIGH, LOW, true, false);
      return TouchState3;
    }

    boolean Touch4() {
      boolean TouchState4 = map(digitalRead(TouchPin4), HIGH, LOW, true, false);
      return TouchState4;
    }
};



class SoundsControl {
  public:

    void begin() {
      pinMode(BuzzerPin , INPUT);
    }

    void ModesNoise(boolean state) {
      if (state == true) {
        tone(BuzzerPin , 30);
      } else if (state == false) {
        tone(BuzzerPin , -30);
        digitalWrite(BuzzerPin, HIGH);
      }

    }

};



class ModesControl {
    TouchSensor Touch;
  public:
    void Modes() {
      boolean TouchSensor1 = Touch.Touch1();
      boolean TouchSensor2 = Touch.Touch2();
      boolean TouchSensor3 = Touch.Touch3();
      boolean TouchSensor4 = Touch.Touch4();

      if (TouchSensor1 == true) {
        TouchState = 1;
      }

      if (TouchSensor2 == true) {
        TouchState = 2;
      }

      if (TouchSensor3 == true) {
        TouchState = 3;
      }

      if (TouchSensor4 == true) {
        TouchState = 4;
      }
    }
};
