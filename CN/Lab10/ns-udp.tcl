set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf

set tr [open udp-120k.tr w]
$ns trace-all $tr

proc finish {} {
    global ns nf
    $ns flush-trace

    close $nf
    exec nam out.nam &

    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

 $ns duplex-link $n0 $n1 1Mb 50ms DropTail
$ns duplex-link $n1 $n2 100Kb 5ms DropTail

$ns queue-limit $n1 $n2 10
$ns duplex-link-op $n1 $n2 queuePos 0.5

set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n2 $null
$ns connect $udp $null
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packetSize_ 1000
$cbr set rate_ 120kb
$cbr set random_ false

$ns at 0.5 "$cbr start"
$ns at 10.5 "$cbr stop"

$ns at 11.0 "finish"

$ns run
