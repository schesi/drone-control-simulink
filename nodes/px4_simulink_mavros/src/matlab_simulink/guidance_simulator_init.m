clear all;
close all;
%% Init file for simulator
% Simulator parameters
simulator.dt = 1/100;
simulator.x0 = [0,0,0,1,2,-1]';
simulator.flag_detect = timeseries(logical([0 1]),[0 100]);
simulator.wps = [0   40
                 0   -100
                 40   40];

% GNC Sub parameters
gnc_sub.controller.kp = 0.8;
gnc_sub.controller.kd = 4;
gnc_sub.guidance.dt = 1/20; %[hz]
