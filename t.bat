call pio test -e target_test -f "test_target_front"
call pio test -e target_test -f "test_target_multishield" 
call pio test -e target_test -f "test_target_wifi"
:: it also tests the buzzer