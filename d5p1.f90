
subroutine solve(d)
  character, dimension(10), intent(in) :: d
  integer :: i, j
  integer, dimension(2) :: rows, cols

  rows = (/ 0, 8 /)
  cols = (/ 0, 128 /)

  do i=1, 10
    write(*,'(10A,2(2(I8)))') d, rows(1), rows(2), cols(1), cols(2)
    write(*,'(10A)') ('~', j=1,i-1), ('^')
    select case(d(i))
    case('F')
      cols(2) = cols(2) - ((cols(2)-cols(1)) / 2)
    case('B')
      cols(1) = cols(1) + ((cols(2)-cols(1))/2)
    case('L')
      rows(2) = rows(2) - ((rows(2)-rows(1)) / 2)
    case('R')
      rows(1) = rows(1) + ((rows(2)-rows(1))/2)
    endselect
  enddo

end subroutine

program d1p1
  implicit none
  integer :: i=1, j, io
  character, dimension(10) :: el
  character(len=16), dimension(3) :: header
  header = (/ 'Input:', 'Rows: ', 'Cols: ' /)

  write(*,'(3(A16))') header

  do
    read(*,'(10A)', IOSTAT=io) el
    if (io > 0) then
      write(*,*) 'Error!'
      exit
    elseif (io < 0) then
      write(*,*) 'Done.'
      exit
    else
      call solve(el)
    endif
  end do

end program d1p1

