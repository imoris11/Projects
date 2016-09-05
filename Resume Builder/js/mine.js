var experiences = 1;
var texp=1;
var skills =1;
var tskills = 1;
var honors = 1;
thonors = 1;
var projects =1;
tprojects = 1;
var community_service = 1;
tcs = 1;
var height = 0;
var nPosition = 85;
var aPosition = 70;
var phPosition = 80;
var pPosition = 85;
var fontSize=8;
var fontType = "Arial"
$("#namePosition").val(nPosition);
$("#addressPosition").val(aPosition);
$("#phonePosition").val(phPosition);
$("#portfolioPosition").val(pPosition);
 function generatePDF(doc){
   doc.rect(5, 5, 201, 288);
   doc.setFont(fontType);
   fillContactInfo(doc);
   fillEducation(doc);
   fillExperience(doc);
   fillSkills(doc);
   fillHonors(doc);
   fillProjects(doc);
   fillCommunity(doc);
 }
$(document).on("click", "#update_preview", function(){
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#work", function(){
  experiences++;
  texp++;
  var exp = "<div id='exp"+experiences+"'><div class='col-sm-10'><p class='lead'>Work Experience </p></div><div class='col-sm-2'><a data-id='"+experiences+"' id='cancel'><i class='fa fa-times fa-2x' area-hidden='true'></i></a></div><div class='form-group row'>";
  exp += "<div class='col-sm-10 col-sm-offset-1'>";
  exp += " <input type='text' class='form-control' id='Institution"+experiences+"' placeholder='Name of Institution'></div></div>";
  exp += "<div class='form-group row'>";
  exp +="<div class='col-sm-10 col-sm-offset-1'>";
  exp +="<input type='text' class='form-control' id='Location"+experiences+"' placeholder='Location of Institution'>";
  exp += "<p id='courseHelpBlock' class='form-text text-muted'>e.g San Francisco, CA</p></div></div>";
  exp +="<div class='form-group row'>";
  exp +="<div class='col-sm-10 col-sm-offset-1'>";
  exp +="<div class='col-sm-6'>";
  exp +="<input type='text' class='form-control' id='StartDate"+experiences+"' placeholder='Start Date'>";
  exp +="<p id='courseHelpBlock' class='form-text text-muted'>e.g May 2017</p></div>";
  exp +="<div class='col-sm-6'>";
  exp +="<input type='text' class='form-control' id='EndDate"+experiences+"' placeholder='End Date or Present ''>";
  exp +="<p id='courseHelpBlock' class='form-text text-muted'>e.g May 2017</p></div></div></div>";
  exp +="<div class='form-group row'>";
  exp +="<div class='col-sm-10 col-sm-offset-1'>";
  exp +="<textarea rows='3' maxlength='200' class='form-control' id='Description"+experiences+"' placeholder='Synopsis of Institution'></textarea>";
  exp +="<p id='courseHelpBlock' class='form-text text-muted'>e.g Design and development of consumer electronics, computer software, and online services.</p></div></div>";
  exp +="<div class='form-group row'>";
  exp +="<div class='col-sm-10 col-sm-offset-1'>";
  exp +="<input type='text' class='form-control' id='jobTitle"+experiences+"' placeholder='Enter Job Title'></div></div>";
  exp +="<div class='form-group row'>";
  exp +="<div class='col-sm-10 col-sm-offset-1'>";
  exp +="<textarea rows='3' class='form-control' id='FRole"+experiences+"' placeholder='Enter a Duty Performed'></textarea>";
  exp +="<p id='courseHelpBlock' class='form-text text-muted'>Hint: Use action words</p></div></div>";
  exp +="<div class='form-group row'>";
  exp +="<div class='col-sm-10 col-sm-offset-1'>";
  exp +="<textarea rows='3' class='form-control' id='SRole"+experiences+"' placeholder='Enter Another Duty Performed'></textarea></div></div></div>";
  $("#myForm").append(exp);
  if(texp === 4){
    $("#work").hide();
  }
});
$(document).on("click", "#skills", function(){
  skills++;
  tskills ++;
  var skill = "<div id='set"+skills+"'><div class='col-sm-10'></div><div class='col-sm-2'><a data-id='"+skills+"' id='cancelSkill'><i class='fa fa-times fa-2x' area-hidden='true'></i></a></div><div class='form-group row'>";
  skill +="<div class='col-sm-10 col-sm-offset-1'>";
  skill +="<textarea rows='3' maxlength='200' class='form-control' id='skill"+skills+"' placeholder='Enter A New Skill'></textarea>";
  skill +="<p id='courseHelpBlock' class='form-text text-muted'>e.g Exceptional strategic and analytical thinking abilities</p></div></div></div>";
  if(tskills ===6){
    $("#skills").hide();
  }
  $("#skillSet").append(skill);
});
$(document).on("click", "#honors", function(){
  honors++;
  thonors++;
  var honor = "<div id='hon"+honors+"'><div class='col-sm-10'><p class='lead'>Honor/Activity </p></div><div class='col-sm-2'><a id='cancelHonor' data-id='"+honors+"'><i class='fa fa-times fa-2x' area-hidden='true'></i></a></div><div class='form-group row'>";
  honor +="<div class='col-sm-10 col-sm-offset-1'>";
  honor +="<textarea rows='3' maxlength='200' class='form-control' id='honor"+honors+"' placeholder='Enter an Activity or Honor'></textarea>";
  honor +="<p id='courseHelpBlock' class='form-text text-muted'>e.g Member of the Horace Mann Bond Honors Program</p></div></div>";
  honor +="<div class='form-group row'>";
  honor +="<div class='col-sm-4 col-sm-offset-1'>";
  honor +="<input type='text' class='form-control' id='StartYear"+honors+"' placeholder='Year Received'>";
  honor +="</div><div class='col-sm-6'>";
  honor +="<input type='text' class='form-control' id='EndYear"+honors+"' placeholder='End Date or Present'>";
  honor +="<p id='courseHelpBlock' class='form-text text-muted'>e.g May 2017</p>";
  honor +="</div></div></div>";
  $("#Activities").append(honor);
  if(thonors === 6){
    $("#honors").hide();
  }
});
$(document).on("click", "#project", function(){
  tprojects++;
  projects++;
  var project = "<div id='pro"+projects+"'><div class='col-sm-10'></div><div class='col-sm-2'><a data-id='"+projects+"' id='cancelProjects'><i class='fa fa-times fa-2x' area-hidden='true'></i></a></div><div class='form-group row'>";
  project += "<div class='col-sm-10 col-sm-offset-1'>";
  project +="<textarea rows='3' maxlength='200' class='form-control' id='project"+projects+"' placeholder='New Project'></textarea>";
  project +="<p id='courseHelpBlock' class='form-text text-muted'>This could be a class project or personal project</p></div></div></div>";
  $("#Projects").append(project);
  if(tprojects===3){
    $("#project").hide();
  }
});
$(document).on("click", "#cs", function(){
  community_service++;
  tcs++;
  var cs = "<div id='cservice"+community_service+"'><div class='col-sm-10'></div><div class='col-sm-2'><a data-id='"+community_service+"' id='cancelCS'><i class='fa fa-times fa-2x' area-hidden='true'></i></a></div><div class='form-group row'>";
  cs +="<div class='col-sm-10 col-sm-offset-1'>";
  cs +="<textarea rows='3' maxlength='200' class='form-control' id='cs"+community_service+"' placeholder='Enter a Community Project'></textarea>";
  cs +="<p id='courseHelpBlock' class='form-text text-muted'>e.g Mapping areas missing on maps through the missing maps project and red cross</p></div></div></div>";
  $("#community").append(cs);
  if(tcs === 2){
    $("#cs").hide();
  }
});
$(document).on("click", "#download", function(){
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  doc.output('save','resume.pdf');
});
$(document).on("click", "#cancelCS", function(){
  tcs--;
  var id = $(this).data("id");
  $("#cservice"+id).hide(100);
  $("#cs"+id).val(" ");
  if(tcs < 2){
    $("#cs").fadeIn(100);
  }
})
$(document).on("click", "#cancel", function(){
  texp--;
  var id = $(this).data("id");
  $("#exp"+id).fadeOut(100);
  clearForm(id);
  if(texp < 4){
    $("#work").fadeIn(100);
  }
});
$(document).on("click", "#cancelSkill", function(){
  tskills--;
  var id=$(this).data("id");
  $("#set"+id).fadeOut(100);
  $("#skill"+id).val(" ");
  if(tskills < 6){
    $("#skills").fadeIn(100);
  }
})
$(document).on("click", "#cancelHonor", function(){
  thonors--;
  var id = $(this).data("id");
  $("#hon"+id).fadeOut(100);
  $("#honor"+id).val(" ");
  if(thonors < 6){
    $("#honors").fadeIn(100);
  }
});
$(document).on("click", "#cancelProjects", function(){
  tprojects--;
  var id = $(this).data("id");
  $("#pro"+id).fadeOut(100);
  $("#project"+id).val(" ");
  if(tprojects < 3){
    $("#project").fadeIn(100);
  }
});
$(document).on("click", "#incName", function(){
  nPosition++;
  $("#namePosition").val(nPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#decName", function(){
  nPosition--;
  $("#namePosition").val(nPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#incAddress", function(){
  aPosition++;
  $("#addressPosition").val(aPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#decAddress", function(){
  aPosition--;
  $("#addressPosition").val(aPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#incPhone", function(){
  phPosition++;
  $("#phonePosition").val(phPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#decPhone", function(){
  phPosition--;
  $("#phonePosition").val(phPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#incPortfolio", function(){
  pPosition++;
  $("#portfolioPosition").val(pPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("click", "#decPortfolio", function(){
  pPosition--;
  $("#portfolioPosition").val(pPosition);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("change", "#fontSize", function(){
  fontSize = $(this).val();
  alert(fontSize);
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
});
$(document).on("change", "#fontType", function(){
  fontType= $(this).val();
  height =0;
  var doc = new jsPDF();
  generatePDF(doc);
  var iframe = document.getElementById('output');
  iframe.style.width = '100%';
  iframe.style.height ='500px';
  iframe.src = doc.output('datauristring');
})
function clearForm(id){
  $("#Institution"+id).val(" ");
}
function fillContactInfo(doc){
  var name = ($("#inputName").val()).toUpperCase();
  doc.setFontSize(fontSize+4);
  height +=13;
  doc.text(nPosition,height, name);
  doc.setFontSize(fontSize);
  height +=4;
  doc.text(aPosition,height, $("#inputAddress").val());
  height +=4;
  var str = $("#inputPhone").val() +" || "+$("#inputEmail").val();
  doc.text(phPosition,height,str);
  height +=4;
  if($("#inputPortfolio").val() !=""){
    doc.text(pPosition,height, "Portfolio: "+$("#inputPortfolio").val());
    height +=4;
  }
  doc.setLineWidth(0.2);
  doc.line(10, height, 200, height);
  height +=3;
}
function fillEducation(doc){
  if($("#inputUniversity").val() != ""){
    doc.setDrawColor(0);
    doc.setFillColor(173,216,230);
    doc.rect(10, height, 190, 5, 'F');
    height +=3;
    doc.text(100,height,"EDUCATION");
    height +=8;
    doc.setFontType('italic');
    doc.text(15,height,$("#inputUniversity").val());
    doc.setFontType('normal');
    doc.text(170,height,$("#inputStartYear").val()+" - Present");
    height +=4;
    doc.setFontType('bold');
    doc.text(15,height,"Major: ");
    doc.setFontType('normal');
    doc.text(25,height, $("#inputMajor").val());
    height +=4;
    if($("#inputMajor2").val() !=""){
      doc.setFontType('bold');
      doc.text(15,height,"Major: ");
      doc.setFontType('normal');
      doc.text(25,height, $("#inputMajor").val() + " AND "+$("#inputMajor2").val());
      height +=4;
    }
    doc.setFontType("bold");
    doc.text(15,height,"GPA: ");
    doc.setFontType("normal");
    doc.text(23,height, $("#inputGPA").val()+"/4.0");
    doc.setFontType("bold");
    height +=4;
    doc.text(15,height,"Expected Graduation Date: ");
    doc.setFontType("normal");
    doc.text(53,height, $("#inputExpected").val());
    height +=4;
    doc.setFontType("bold");
    doc.text(10,height,"Related Courses: ");
    doc.setFontType("normal");
    var str = doc.splitTextToSize($("#inputCoursework").val(), 165);
    doc.text(36,height,str);
    height +=9;
  }
}
function fillExperience(doc){
  if($("#Institution1").val() != ""){
    doc.setDrawColor(0);
    doc.setFillColor(173,216,230);
    doc.rect(10, height, 190, 5, 'F');
    height +=3;
    doc.text(97,height,"WORK EXPERIENCE");
    height +=6;
    for(var i=1; i<= experiences; i++){
      if($("#Institution"+i).val() != " "){
        var inst = $("#Institution"+i).val();
        var loc = $("#Location"+i).val();
        var StartDate = $("#StartDate"+i).val();
        var EndDate = $("#EndDate"+i).val();
        var str ="";
        if(inst != ""){
          if(inst == loc){
              str = inst +" ( "+StartDate+" - "+EndDate+" ) ";
          }else{
              str = inst +", "+loc + " ( "+StartDate+" - "+EndDate+" ) ";
          }
        }

        doc.setFontType("bold");
        doc.text(10,height, str.toUpperCase());
        height +=4;
        doc.setFontType("normal");
        if($("#Description"+i).val() != ""){
          doc.text(10,height, $("#Description"+i).val());
          height +=4;
        }
        var title = $("#jobTitle"+i).val();
        str = title +  " ( "+StartDate+" - "+EndDate+" )";
        doc.setFontType("bold");
        doc.text(10,height, str);
        doc.setFontType("normal");
        height +=4;
        doc.setFillColor(0,0,0);
        doc.circle(15, height-1, 0.5, "FD");
        doc.text(17,height, $("#FRole"+i).val());
        height +=4;
        if($("#SRole"+i).val() !=""){
          doc.setFillColor(0,0,0);
          doc.circle(15, height-1, 0.5, "FD");
          doc.text(17, height, $("#SRole"+i).val());
          height +=5;
        }
      }
      //end
    }
  }
}
function fillSkills(doc){
  if($("#skill1").val() != ""){
    doc.setDrawColor(0);
    doc.setFillColor(173,216,230);
    doc.rect(10, height, 190, 5, 'F');
    height +=3;
    doc.text(103,height,"SKILLS");
    height +=6;
    doc.setFillColor(0,0,0);
    for(var i=1; i<=skills; i++){
      if($("#skill"+i).val() != " "){
        doc.circle(15, height-1, 0.5, "FD");
        doc.text(17, height, $("#skill"+i).val());
        height +=4;
      }
    }
  }
}
function fillHonors(doc){
  if($("#honor1").val() != ""){
    doc.setFillColor(173,216,230);
    doc.rect(10, height, 190, 5, 'F');
    height +=3;
    doc.text(85,height,"ACADEMIC HONORS / ACTIVITIES");
    height +=6;
    doc.setFillColor(0,0,0);
    for(var i=1; i<=honors; i++){
      if($("#honor"+i).val() != " "){
        doc.circle(15, height-1, 0.5, "FD");
        StartDate = $("#StartYear"+i).val();
        EndDate = $("#EndYear"+i).val();
        var str = "";
        doc.text(17, height, $("#honor"+i).val());
        if(EndDate != ""){
           str = StartDate + " - " + EndDate;
        }else{
           str = StartDate;
        }
        doc.text(170,height, str);
        height +=4;
      }
    }
  }
}
function fillProjects(doc){
  if($("#project1").val() != ""){
    doc.setFillColor(173,216,230);
    doc.rect(10, height, 190, 5, 'F');
    height +=3;
    doc.text(100,height,"PROJECTS");
    height +=6;
    doc.setFillColor(0,0,0);
    for(var i=1; i<=projects; i++){
      if($("#project"+i).val() != " "){
        doc.circle(15, height-1, 0.5, "FD");
        var str = doc.splitTextToSize($("#project"+i).val(), 180);
        doc.text(17, height, str);
        height +=4;
      }
    }
  }
}
function fillCommunity(doc){
  if($("#cs1").val() != ""){
    doc.setFillColor(173,216,230);
    doc.rect(10, height, 190, 5, 'F');
    height +=3;
    doc.text(90,height,"COMMUNITY SERVICE");
    height +=6;
    doc.setFillColor(0,0,0);
    for(var i=1; i<=community_service; i++){
      if($("#cs"+i).val() != " "){
        doc.circle(15, height-1, 0.5, "FD");
        var str = doc.splitTextToSize($("#cs"+i).val(), 180);
        doc.text(17, height, str);
        height +=4;
      }
    }
  }
}
