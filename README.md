# sih_mattress
sih 2020_warm patient mattress

Problem Statement​ : Humans normally maintain a body temperature at 37°C, and maintenance
of this relatively high temperature is critical to human survival. Our bodies are designed to
tightly control our internal temperature, no matter what the external temperature is. Operating
temperature in a CT/MRI/PET exam room is normally between 18deg C to 26 Deg C and kept
on an average ~22Deg C. Since room temperature is lower than your body temperature, contact
surface of medical device (mattress, pad, support surfaces etc..) quickly absorb the heat from
patient’s skin, making patient feel cold. This discomfort to patient during medical imaging
/Interventional procedures increases the negative patient outcome due to patient shivering &
unintended patient motion. Due to this cold temperature, patients may activate “brown” fat at
contact surface which contains adrenergic receptors and generates heat by metabolizing
glucose. This can show up on scans and potentially hide true “lesions” in PET imaging.
Currently hospitals uses blankets to cover or to enfold a great portion of the Patient's body
during scan to trap radiant bodily heat and keeping the body warm. Hospitals uses a lot of
blankets as each patient requires a new / washed blanket.. busy centers will go through on avg.
10 blankets in a day. Key Constraints: User adjustable temperature Automated temperature
control to set temperature “ Range 20°C -40°C”. Quick response to set temperature within 3
min. Mattress/Pad material:- Radiolucency , MR Compatibility, Biocompatible and Easy to clean.
Comfortable foam pad Mattress/pad size: 2mtr length x 0.42 mtr width On/Off switch and
Indicator Accurate measurement of temperature of warm mattress/bed (Tolerance +/-1 Deg)
Current temperature display of the heating pad/mattress all the time. Fail safe heating
mechanism-redundant temperature cut off mechanism Goal : Develop a ~2 meter long warm
patient mattress/pad to provide mild warmness to patients during Imaging systems
(PET/CT/MRI/Interventional Imaging Systems)

Solution approach:
A heating bag/pad will be used , whose temperature will be monitored and will be controlled by
a microcontroller using a PID control algorithm to maintain a constant temperature. The
following devices will be used for building a working prototype:
1. Heating bag/pad
2. Nodemcu (esp8266) / arduino
3. Temperature and humidity sensor (dht11)
4. relay( for AC source) or l298 motor controller (for DC source)
5. Arduino ideSolution:

Code implementation
The data from temperature sensor will be used by the PID control algorithm to generate the
desired pwm signal to control the power fed from the source to the mattress via a relay module (
if the source is AC) or a l298 motor controller ( if the source is DC).
PID control: A target temperature will be set (eg. 37 degree celsius). The difference from the
reading of the temperature sensor and target temperature will be assigned to the error variable.
The error will then be multiplied by a proportional constant , it’s integral by a integral constant
and the rate of change of difference in current error and the previous error by a derivative
constant, followed by their summation will be fed to the relay/l298 motor controller to control the
supply power to heat the mattress.
The PID control algorithm will be implemented in the arduino ide code itself.
The control of target temperature of the matress can be done by an app, which will also be
designed. The target temperature will be entered in the app will be updated on the clouddatabase (eg. firebase). Nodemcu will fetch the data from the cloud and set it as the target
temperature in the pid control algorithm. Multiple mattresses can also be controlled with the app.
