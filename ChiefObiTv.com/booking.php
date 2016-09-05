<?php
require_once("header.php");
require_once("db.php");
?>
  <!-- Start contact section  -->
  <section id="contact">
     <div class="container">
       <div class="row">
         <div class="col-md-12">
           <div class="title-area">
              <h2 class="title">Bookings</h2>
              <span class="line"></span>
              <p class="lead contact_info">Need me at an Event? Book me below. Dates highlighted are already booked. </p>
            </div>
         </div>
         <div class="col-md-12">
           <div class="cotact-area">
             <div class="row">
               <div class="col-md-6">
                   <div id="confirmBooking"></div>
                 <div class="contact-area-left">
                   <form class="form-horizontal" method="post" action="save_event.php">
                       <div class="row">
                            <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="event" >Name</label>
                                </div>
                                <div class="col-md-8">
                                <input class="form-control" name="name" id="name" type="text" placeholder="Enter Your Name">
                                <p class="warning" id="name_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="phone" >Phone</label>
                                </div>
                                <div class="col-md-8">
                                <input class="form-control" name="phone" id="phone" type="text" placeholder="Enter Phone">
                                <p class="warning" id="phone_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="email" >Email</label>
                                </div>
                                <div class="col-md-8">
                                <input class="form-control" name="email" id="email" type="text" placeholder="Enter Email">
                                <p class="warning" id="email_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="event" >Event Title</label>
                                </div>
                                <div class="col-md-8">
                                <input class="form-control" name="event" id="event" type="text" placeholder="Enter Title Of Event">
                                <p class="warning" id="event_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="location" >Location</label>
                                </div>
                                <div class="col-md-8">
                                <input class="form-control" name="location" id="location" type="text" placeholder="Location of Event">
                                <p class="warning" id="location_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="date" > Date</label>
                                </div>
                                <div class="col-md-8">
                                <input class="form-control" name="date" id="date" type="date" placeholder="Enter Title Of Event">
                                <p class="warning" id="date_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                <label for="event" >Special Notes</label>
                                </div>
                                <div class="col-md-8">
                                    <textarea class="form-control" name="notes" rows="5" type="text" id="notes" placeholder="Enter Notes For Chief Obi"></textarea>
                                    <p class="warning" id="notes_warning"></p>
                                </div>
                           </div>
                           <div class="form-group">
                                <div class="col-md-4 text-center">
                                </div>
                                <div class="col-md-8">
                                <input class="btn btn-danger" name="submit" id="submitButton" value="Submit Booking" >
                                <input class="btn btn-danger" type="submit" name="submit" id="submitButton" value="Submit Booking" >
                                </div>
                           </div>
                       </div>
                     </form>
                    </div>
                 </div>
                  <div class="col-md-6">
                    <div id="my-calendar"></div>
               </div>
               </div>
             </div>
           </div>
         </div>
       </div>
     </div>
  </section>
  <!-- End contact section  -->
<?php
require_once("footer.php")
?>
