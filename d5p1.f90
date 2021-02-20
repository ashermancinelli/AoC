
subroutine solve(d, ma, debug)
  character, dimension(10), intent(in) :: d
  integer, intent(out) :: ma
  logical, intent(in) :: debug
  integer :: i, j
  integer, dimension(2) :: rows, cols, delta

  rows = (/ 0, 8 /)
  cols = (/ 0, 128 /)

  do i=1, 10
    if (debug) then
      write(*,'(10A,2(2(I8)))') d, rows(1), rows(2), cols(1), cols(2)
      write(*,'(10A)') ('~', j=1,i-1), ('^')
    endif

    ! Adding one for rounding
    delta(1) = (cols(2) - cols(1)) ! + 1
    delta(2) = (rows(2) - rows(1)) ! + 1
    delta = (delta+1) / 2

    select case(d(i))
    case('F')
      cols(2) = cols(2) - delta(1)
    case('B')
      cols(1) = cols(1) + delta(1)
    case('L')
      rows(2) = rows(2) - delta(2)
    case('R')
      rows(1) = rows(1) + delta(2)
    endselect
  enddo

  write(*,'(10A,3(I16))') d, rows(1), cols(1), ((cols(1)*8)+rows(1))
  ma = (cols(1)*8)+rows(1)

end subroutine

program d1p1
  implicit none
  integer :: i=1, j, io, ma
  character, dimension(10) :: el
  character(len=16), dimension(4) :: header
  header = (/ 'Input:', 'Rows: ', 'Cols: ', 'Mul:  ' /)

  write(*,'(4(A16))') header

  i = 0
  do
    read(*,'(10A)', IOSTAT=io) el
    if (io > 0) then
      write(*,*) 'Error!'
      exit
    elseif (io < 0) then
      exit
    else
      call solve(el, j, .false.)
      i = max(i, j)
    endif
  end do
  write(*,*) i

end program d1p1

