
subroutine solve(d, mat, debug)
  character, dimension(10), intent(in) :: d
  integer, dimension(8,128), intent(inout) :: mat
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
  mat(rows(1), cols(1)) = (cols(1)*8)+rows(1)

end subroutine

program prog
  implicit none
  integer :: i=1, j, io, ma
  integer :: mat(8, 128)
  logical :: mask(8, 128)
  integer, allocatable :: ar(:)
  character, dimension(10) :: el
  character(len=16), dimension(4) :: header
  header = (/ 'Input:', 'Rows: ', 'Cols: ', 'Mul:  ' /)

  mat = 0
  mask = .true.
  mask(:,:8) = .false.
  mask(:,120:) = .false.

  write(*,'(4(A16))') header

  do
    read(*,'(10A)', IOSTAT=io) el
    if (io > 0) then
      write(*,*) 'Error!'
      exit
    elseif (io < 0) then
      exit
    else
      call solve(el, mat, .false.)
    endif
  end do

  write(*,*) 'Matrix:'
  write(*,'(A3,8I8)') '   ', (j,j=1,8)
  write(*,'(68A)') '   ', ('_', j=1,65)
  do j=1, 128
    write(*,'(I3,A,8I8)') j, '|', mat(:,j)
  enddo

  ! write(*,*) 'Mask:'
  ! write(*,'(A3,8I8)') '   ', (j,j=1,8)
  ! write(*,'(68A)') '   ', ('_', j=1,65)
  ! do j=1, 128
  !   write(*,'(I3,A,8L8)') j, '|', mask(:,j)
  ! enddo

  i = maxval(mat)
  write(*,*) ''
  write(*,*) 'Maxval = ', i

  allocate(ar(size(shape(mat))))
  ar = minloc(mat, mask=mask)
  write(*,*) 'Minloc = ', ar
  write(*,*) 'Answer = ', (ar(2)*8 + ar(1))
  deallocate(ar)

end program
