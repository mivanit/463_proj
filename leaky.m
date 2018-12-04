clearvars
clearvars -global
% PARAMETERS -------------------------------------------------------------  
R = 10e6;      % membrane resistance [ohms]
tau = 20;      % time constant [s]
I0 = 1.3e-6;   % external current amplitude [mA]   
N = 10000;     % number of data points for calculations
vTH = -50;     % threshold voltage
vRest = -60;   % rest potential
vReset = -80;  % reset potential
vSpike = -10;  % spike potential
refP = 5;      % absolute refractory period
de = 0.99;      % decay rate of inhibitory neurotransmitters
inhibit = 1;   % 1 -> use inhibitory neurotransmitters, 0 -> don't use
   
% SETUP ------------------------------------------------------------------
% time interval for modeling
tmin = 0;
tmax = 50*tau;
t = linspace(tmin, tmax, N);
dt = t(2) - t(1);

% Membrane voltage [mV] for neuron 1
V = vRest .* ones(1, N);
% Membrane current [mA] for neuron 1                  
Iext = zeros(1, N);
% Membrane voltage [mV] for neuron 2
V2 = vRest .* ones(1, N);
% Membrane current [mA] for neuron 2                
Iext2 = zeros(1, N);
% Inhibitory neurotransmitter 1
E = zeros(1, N);
% Inhibitory neurotransmitter 2
E2 = zeros(1, N);
   
% EXTERNAL STIMULUS  -----------------------------------------------------
s = 50;         % How far apart the pulses are between the neur
num_pulses = 6;  % How many pulses for neuron 1
num_pulses2 = 6;  % How many pulses for neuron 2
pulse_len = 500; % Length of each pulse (same for both neurons)
ratio = 1;       % current2/current1
ix = zeros(num_pulses, 1);
ix2 = zeros(num_pulses, 1);
for i = 1:num_pulses
    ix(i) = round(i * 2 * pulse_len);
    Iext(ix(i):ix(i)+pulse_len)=I0;
end
for i = 1:num_pulses2
    ix2(i) = round(i * 2 * pulse_len);
    Iext2(ix2(i)+s:ix2(i)+pulse_len+s)=ratio*I0;
end

% Finite Difference method  ==============================================
d1 = 0;
d2 = 0;
for c = 1 : N - 1
   V(c+1)=V(c)+(dt/tau) * (-V(c)+vRest+R*Iext(c));
   V2(c+1)=V2(c)+(dt/tau) * (-V2(c)+vRest+R*Iext2(c));
   E(c+1)=de*E(c)*inhibit;
   E2(c+1)=de*E2(c)*inhibit;
   
   % Spike if threshold met, then reset immediately after
   if V(c+1) > vTH
       V(c) = vSpike;
       V(c+1) = vReset;
       d1 = round(refP / dt);
       E(c+1)=inhibit;
   end
   if V2(c+1) > vTH
       V2(c) = vSpike;
       V2(c+1) = vReset;
       d2 = round(refP / dt);
       E2(c+1)=inhibit;
   end
   
   % Keep voltage fixed during refractory period
   if d1 > 0
       V(c+1) = vReset;
       d1 = d1 - 1;
   end
   if d2 > 0
       V2(c+1) = vReset;
       d2 = d2 - 1;
   end
end

% GRAPHICS  ==============================================================
plot(t, V, 'linewidth', 2)
hold on
plot(t, V2, '--', 'linewidth', 1);
plot(linspace(0,N*dt), linspace(vTH,vTH), ':', 'linewidth', 1.5);
xlabel('t [ms]');
ylabel('V [mV]');
legend('Neuron 1', 'Neuron 2', 'Threshold Voltage')
axis([0 0.5*tmax -inf inf])
if inhibit == 1
    title('Inhibitory Action')
elseif inhibit == 0
    title('No Inhibitory Action')
end
hold off